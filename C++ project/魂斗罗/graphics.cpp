#include <windows.h>  
#include "graphics.h"
#include "globals.h"

//������ֱ��ʹ��FC��tile (16�ֽ� 8�ֽ�λƽ��0, 8�ֽ�λƽ��1)
//���ֱ�ֱ����FC��4��(64*64), ����X��0-511, Y��0-479
//���ֱ��tile��32λ, ��2λ��ɫ��. ��16Ϊ��tile#
//���Ա�(16*16)����ͬFC, �����ֱ��tile��ֱ��ָ����ɫ��
//SP��XY����32λ, SP��������32λ (��3λ��Y��ת, X��ת, �����ȼ�, ��2λ��ɫ��)
//VROM��8K, ǰ��̶���SP tiles, �����BG tiles
//
//V��ַ����:
//0x0000-0x1FFF		VROM
//0x2000-0x2FFF		���ֱ� (��FC��ͬ)
//0x3000-0x30FF		���Ա� (��FC��ͬ)
//0x3F00-0x3F0F		Bgpal
//0x3F10-0x3F1F		Sppal

//FCӲ����ɫ��
static PALBUF NesPalette[] = {
	0x7F, 0x7F, 0x7F, 0x20, 0x00, 0xB0, 0x28, 0x00, 0xB8, 0x60, 0x10, 0xA0, 0x98, 0x20, 0x78, 0xB0,
	0x10, 0x30, 0xA0, 0x30, 0x00, 0x78, 0x40, 0x00, 0x48, 0x58, 0x00, 0x38, 0x68, 0x00, 0x38, 0x6C,
	0x00, 0x30, 0x60, 0x40, 0x30, 0x50, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0xBC, 0xBC, 0xBC, 0x40, 0x60, 0xF8, 0x40, 0x40, 0xFF, 0x90, 0x40, 0xF0, 0xD8, 0x40, 0xC0, 0xD8,
	0x40, 0x60, 0xE0, 0x50, 0x00, 0xC0, 0x70, 0x00, 0x88, 0x88, 0x00, 0x50, 0xA0, 0x00, 0x48, 0xA8,
	0x10, 0x48, 0xA0, 0x68, 0x40, 0x90, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0xFF, 0xFF, 0xFF, 0x60, 0xA0, 0xFF, 0x50, 0x80, 0xFF, 0xA0, 0x70, 0xFF, 0xF0, 0x60, 0xFF, 0xFF,
	0x60, 0xB0, 0xFF, 0x78, 0x30, 0xFF, 0xA0, 0x00, 0xE8, 0xD0, 0x20, 0x98, 0xE8, 0x00, 0x70, 0xF0,
	0x40, 0x70, 0xE0, 0x90, 0x60, 0xD0, 0xE0, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0xFF, 0xFF, 0xFF, 0x90, 0xD0, 0xFF, 0xA0, 0xB8, 0xFF, 0xC0, 0xB0, 0xFF, 0xE0, 0xB0, 0xFF, 0xFF,
	0xB8, 0xE8, 0xFF, 0xC8, 0xB8, 0xFF, 0xD8, 0xA0, 0xFF, 0xF0, 0x90, 0xC8, 0xF0, 0x80, 0xA0, 0xF0,
	0xA0, 0xA0, 0xFF, 0xC8, 0xA0, 0xFF, 0xF0, 0xA0, 0xA0, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//RGBǿ�������� (����PPU $2001�ı���ɫ�ʻ�Ũ��λ(0-7) ����)
static	float	PalConvTbl[][3] = {
	1.00f, 1.00f, 1.00f,	//R=G=B
	1.00f, 0.80f, 0.73f,	//R G- B- (ƫ��)
	0.73f, 1.00f, 0.70f,	//R- G B- (ƫ��)
	0.76f, 0.78f, 0.58f,	//R- G- B--
	0.86f, 0.80f, 1.00f,	//R- G- B (ƫ��)
	0.83f, 0.68f, 0.85f,	//R- G-- B-
	0.67f, 0.77f, 0.83f,	//R-- G- B-
	0.68f, 0.68f, 0.68f,	//R- B- C-
};

//��ɫ��ɫ��PC��ʽ��ɫ��
//	ÿ������8��, ��ӦRGBǿ����8��ģʽ
//	ÿ��ֻ��ǰ64ɫ
static	unsigned int	CPalette[8][256];	// ��ɫ       (ǰ64��ɫ��)
static	unsigned int	MPalette[8][256];	// ��ɫ       (ͬ��)

unsigned char Renderbuf[RENDER_W*SCREEN_H];	//����ͼ�������
											//ÿ��1�ֽ�, ��ֵ��Ӳ����ɫ�������
											//��Ӳ����ɫ��ת����, ����������Ļ���
unsigned char LineColormode[SCREEN_H];		//RGBǿ������ɫģʽ����
unsigned int Nametbl[64*60];	//���ֱ�, 64T*60T (ֱ���൱��4��NES�����ֱ�)
unsigned char Ntattrib[256];	//���ֱ����Ա�(16*16)
								//�����������ֱ�����ӦT��ɫ��λ
unsigned char Vrom[8192]={
	0x7c,0xce,0xce,0xce,0xce,0xce,0x7c,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfe,0x0e,0x38,0x7c,0x0e,0x8e,0x7c,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

unsigned char Bgpal[256]={	//������ɫ�� (��ֵ��Ӳ����ɫ�������)
	0xf,0xf,0xf,0xf,
	0xf,0xf,0xf,0xf,
	0xf,0xf,0xf,0xf,
	0xf,0xf,0xf,0xf
};
unsigned char Sppal[256]={
	0xf,0xf,0xf,0xf,
	0xf,0xf,0xf,0xf,
	0xf,0xf,0xf,0xf,
	0xf,0xf,0xf,0xf
};	//SP��ɫ�� (��ֵ��Ӳ����ɫ�������)

SPRITE Spram[64];

short Scrollx=0, Scrolly=0;//(0-511);

//contro reg
unsigned char vcontol=0;

unsigned short V_addr=0;
int V_inc_mode=0;

unsigned char Bit2Rev[256];

void Render32bpp_Normal( unsigned char* lpRdr);
void Render16bpp_Normal( unsigned char* lpRdr);

void (*blitter) ( unsigned char* lpRdr);

int framerate=60;

int initVedeo(int fullscreen){
	DEVMODE dmode;
	unsigned int eflag =0;
	unsigned int freq;

	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dmode);
	freq =dmode.dmDisplayFrequency;
	if (freq<57){
		if (fherr)
			fprintf(fherr, "��Ļˢ���ʹ���\n");
		return 0;
	}
	else if (freq<60){
		framerate=freq;
	}else{
		framerate=60;
	}

	if (fullscreen)
		eflag =SDL_FULLSCREEN | SDL_DOUBLEBUF;
	g_screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 0, SDL_ANYFORMAT | SDL_HWSURFACE | eflag);
	if (!g_screen){
		if (fherr)
			fprintf(fherr, "SDL������ʾģʽʧ��\n");
		return 0;
	}

	if (g_screen->format->BitsPerPixel==32)
		blitter=Render32bpp_Normal;
	else if (g_screen->format->BitsPerPixel==16)
		blitter=Render16bpp_Normal;
	else{
		if (fherr)
			fprintf(fherr, "����������ɫ��λ��,ֻ֧��16λ��32λɫ��\n");
		return 0;
	}

	CalcPaletteTable();
	memset(LineColormode,0,SCREEN_H);

	vcontol =0 | BGDISP_BIT | SPDISP_BIT;

	for( int i = 0; i < 256; i++ ) {
		unsigned char m = 0x80;
		unsigned char c = 0;
		for( int j = 0; j < 8; j++ ) {
			if( i&(1<<j) ) {
				c |= m;
			}
			m >>= 1;
		}
		Bit2Rev[i] = c;
	}
	for(int i = 0; i < 64; i++ ) {
		Spram[i].y=SCREEN_H;
	}

	return 1;
}

void CalcPaletteTable(){
int	i, j;

	int	Rloss, Gloss, Bloss;
	int	Rsft, Gsft, Bsft;

	Rloss =g_screen->format->Rloss;
	Gloss =g_screen->format->Gloss;
	Bloss =g_screen->format->Bloss;
	Rsft =g_screen->format->Rshift;
	Gsft =g_screen->format->Gshift;
	Bsft =g_screen->format->Bshift;
	
	for( j = 0; j < 8; j++ ) {
		for( i = 0; i < 64; i++ ) {
			unsigned int	Rn, Gn, Bn;

			//�ȶ�FCӲ����ɫ�����RGBǿ������
			Rn = (unsigned int)(PalConvTbl[j][0]*NesPalette[i].r);
			Gn = (unsigned int)(PalConvTbl[j][1]*NesPalette[i].g);
			Bn = (unsigned int)(PalConvTbl[j][2]*NesPalette[i].b);

			//��256ɫģʽ�õ�Ӳ����ɫ��Ҫת��
			//(֮����Ҫ����(8-bit)λ, ����Ϊ��ЩRGB����1�ֽ�(8λ) )
			CPalette[j][i] = ((Rn>>Rloss)<<Rsft) | ((Gn>>Gloss)<<Gsft) | ((Bn>>Bloss)<<Bsft);

			// �ڰ� (��������ͬ��)
			// 4���Ҷ� (64����ɫ��ÿ16���γ�һ�ֻҶ�)
			Rn = (unsigned int)(NesPalette[i&0x30].r);
			Gn = (unsigned int)(NesPalette[i&0x30].g);
			Bn = (unsigned int)(NesPalette[i&0x30].b);
			//����������
			Rn = 
			Gn = 
			Bn = (unsigned int)(0.299f * Rn + 0.587f * Gn + 0.114f * Bn);
			//����RGBǿ������
			Rn = (unsigned int)(PalConvTbl[j][0]*Rn);
			Gn = (unsigned int)(PalConvTbl[j][1]*Gn);
			Bn = (unsigned int)(PalConvTbl[j][2]*Bn);
			//Ƕλ
			if( Rn > 0xFF ) Rn = 0xFF;
			if( Gn > 0xFF ) Gn = 0xFF;
			if( Bn > 0xFF ) Bn = 0xFF;

			MPalette[j][i] = ((Rn>>Rloss)<<Rsft) | ((Gn>>Gloss)<<Gsft) | ((Bn>>Bloss)<<Bsft);
		}//for( i = 0; i < 64; i++ )
	}//for( j = 0; j < 8; j++ )
}

void DrawBG(){
	int i,j,k;
	unsigned char* lpScanline, *pScn;
	int Tx=(Scrollx &0x1ff)>>3, tx=Scrollx &7;
	int tsy;
	int Ty, ty;
	int ntbladr, ntbl_x;//��ǰ���ֱ����ַ, ��ǰ���ֱ��� (2���ĵ�6λͬ���仯)
	int tileadr, cg, cache_tile=-1,cache_cg=-1;
	unsigned int code;
	unsigned char* pBGPAL;
	unsigned char BGwrite[33+1];
	unsigned char* pBGw;
	unsigned char SPwrite[33+1];
	unsigned char* pSPw;
	unsigned char chr_h, chr_l;
	int	spraddr; //ͼ�����ھ��鱾���е�λ�� (���Ǿ���V��ת)
	int sp_y;	//��ɨ�����뾫��y֮��, ��Ϊ��澫��ڼ��е�����
	int sp_h;	//�������򳤼�1 (7��15)
	SPRITE* sp;
	unsigned char SPpat;
	int SPpos;
	int SPsft;
	unsigned char SPmsk;
	unsigned short SPwrt;
	unsigned char* pSPPAL;

	int loopy_shift, loopy_y;

	tsy =Scrolly % 480;
	if (tsy<0)
		tsy+=480;
	Ty=tsy>>3;	ty=tsy &7;

	loopy_y=ty;
	loopy_shift=tx;

	for (i=0; i<SCREEN_H; i++){
		lpScanline =Renderbuf +i*RENDER_W;
		LineColormode[i] = ( (vcontol & COLORMODE_BIT)<<7) | (vcontol & BGCOLOR_BIT);//������Щֵ����ÿ�л��

		if (!(vcontol & BGDISP_BIT)){
			memset( lpScanline, Bgpal[0], RENDER_W );
			continue;
		}
		pScn = lpScanline+(8-loopy_shift);//ÿ����1��tile��8
		ntbladr =Ty*64+Tx;//ÿ����1��tile��1 (������һtile)
		ntbl_x =ntbladr & 0x3f;

		pBGw = BGwrite;//ÿ����1��tile��1
		for(j = 0; j < 33; j++ ){
			//���㵱ǰtile�ĵ�(tile��y)������ͼ�����ڵĵ�ַ
			//(tile��*16+(tile��y)), ÿT 16�ֽ�(2����, B0T��B1T), ÿT����1�ֽ�, 
			code =Nametbl[ntbladr & 0xFFF];
			tileadr =0x1000+((code &0xffff)<<4)+ loopy_y;
			cg=(code&0xc0000000)>>28;
			pBGPAL =&Bgpal[cg];
			if( cache_tile == tileadr && cache_cg == cg){
				*(unsigned int*)(pScn+0) = *(unsigned int*)(pScn-8);
				*(unsigned int*)(pScn+4) = *(unsigned int*)(pScn-4);
				*(pBGw+0) = *(pBGw-1);
			}else{
				cache_tile = tileadr;
				cache_cg = cg;
				chr_l = Vrom[tileadr];
				chr_h = Vrom[tileadr+8];
				*pBGw = chr_h|chr_l;
				{
					register int c1 = ((chr_l>>1)&0x55)|(chr_h&0xAA);
					register int c2 = (chr_l&0x55)|((chr_h<<1)&0xAA);
					//8��ֱ���ɫ��, ����ֵд�뱾ɨ���������
					pScn[0] = pBGPAL[(c1>>6)];
					pScn[1] = pBGPAL[(c2>>6)];
					pScn[2] = pBGPAL[(c1>>4)&3];
					pScn[3] = pBGPAL[(c2>>4)&3];
					pScn[4] = pBGPAL[(c1>>2)&3];
					pScn[5] = pBGPAL[(c2>>2)&3];
					pScn[6] = pBGPAL[c1&3];
					pScn[7] = pBGPAL[c2&3];
				}
			}
			//��ɨ���е������λ�ü���������ָ�����
			pScn+=8;
			pBGw++;
			if( ++ntbl_x == 64 ) {
				//��tileX��Ϊ64���0
				ntbl_x = 0;//tileX��0
				ntbladr ^= 0x3F;//XXXXXX���� (ע���ʱ��XXXXXXΪ0x3F)
			} else {
				ntbladr++;
			}
		}//for(j = 0; j < 33; j++ )

		if( !(vcontol & SPDISP_BIT) ) {
			continue;
		}

		pBGw = BGwrite;
		pSPw = SPwrite;
		memset( SPwrite,0, sizeof(SPwrite) );
		sp=Spram;
		sp_h = (vcontol & SP16_BIT)?15:7;

		for(k = 0; k < 64; k++, sp++ ) {
			sp_y = i - (sp->y+1);
			if( sp_y != (sp_y & sp_h) )
				continue;

			if( !(vcontol & SP16_BIT) ) {
				spraddr = sp->tile<<4;
				if( !(sp->attr&SP_VMIRROR_BIT) )
					spraddr += sp_y;
				else
					spraddr += 7-sp_y;
			}else{
				spraddr = ((sp->tile&1)<<12)+((sp->tile&0xFE)<<4);
				if( !(sp->attr&SP_VMIRROR_BIT) )
					spraddr += ((sp_y&8)<<1)+(sp_y&7);
				else
					spraddr += ((~sp_y&8)<<1)+(7-(sp_y&7));
			}

			chr_l = Vrom[spraddr];
			chr_h = Vrom[spraddr+8];

			if( sp->attr&SP_HMIRROR_BIT ) {
				chr_l = Bit2Rev[chr_l];
				chr_h = Bit2Rev[chr_h];
			}
			SPpat = chr_l|chr_h;

			SPpos = (sp->x&0xff)/8;
			SPsft = 8-(sp->x&7);
			SPmsk = ( ((unsigned short)pSPw[SPpos+0]<<8)|
						(unsigned short)pSPw[SPpos+1] ) >>SPsft;
			SPwrt = (unsigned short)SPpat<<SPsft;
			pSPw[SPpos+0] |= SPwrt >> 8;
			pSPw[SPpos+1] |= SPwrt & 0xFF;

			SPpat &= ~SPmsk;

			if( sp->attr&SP_PRIORITY_BIT ) {
				int BGpos = ((sp->x&0xF8)+((loopy_shift+(sp->x&7))&8))>>3;
				int BGsft = 8-((loopy_shift+sp->x)&7);
				unsigned char BGmsk = (((unsigned short)pBGw[BGpos+0]<<8)|(unsigned short)pBGw[BGpos+1])>>BGsft;

				SPpat &= ~BGmsk;

			}

			pSPPAL = &Sppal[(sp->attr&SP_COLOR_BIT)<<2];
			if (sp->x<-8)
				sp->x=-8;
			else
				if (sp->x>=0x100)
					sp->x =0x100;
			pScn   = lpScanline+sp->x+8;

			register int c1 = ((chr_l>>1)&0x55)|(chr_h&0xAA);
			register int c2 = (chr_l&0x55)|((chr_h<<1)&0xAA);
			if( SPpat&0x80 ) pScn[0] = pSPPAL[(c1>>6)];
			if( SPpat&0x08 ) pScn[4] = pSPPAL[(c1>>2)&3];
			if( SPpat&0x40 ) pScn[1] = pSPPAL[(c2>>6)];
			if( SPpat&0x04 ) pScn[5] = pSPPAL[(c2>>2)&3];
			if( SPpat&0x20 ) pScn[2] = pSPPAL[(c1>>4)&3];
			if( SPpat&0x02 ) pScn[6] = pSPPAL[c1&3];
			if( SPpat&0x10 ) pScn[3] = pSPPAL[(c2>>4)&3];
			if( SPpat&0x01 ) pScn[7] = pSPPAL[c2&3];
		}//for( int k = 0; k < 64; k++, sp++ )



		if( loopy_y == 7 ) {
			loopy_y =0;
			//tileY�Ѿ���59? (�ǵĻ�Ҫ��0����)
			if( Ty == 59 ) {
				Ty=0;
			} else {
				Ty++;
			}
		} else {
			loopy_y++;
		}
	}//for (int i=0; i<SCREEN_H; i++)
}

void nesBlit(){
	blitter(&Renderbuf[8]);
}

void	Render32bpp_Normal( unsigned char* lpRdr)
{
	SDL_LockSurface(g_screen);

	unsigned char*	pScn = lpRdr;
	unsigned char*	pDst = (unsigned char*)g_screen->pixels;
	unsigned char*	pPal;
	unsigned char*	pColormode =LineColormode;
	unsigned int	width;
	unsigned int	pitch = g_screen->pitch;

	for( int i = 0; i < SCREEN_H; i++ ) {
		if( !(pColormode[i]&0x80) ) {
			pPal = (unsigned char*)CPalette[pColormode[i]&0x07];
		} else {
			pPal = (unsigned char*)MPalette[pColormode[i]&0x07];
		}

		width = SCREEN_W;

		__asm {
			mov		eax, pScn
			mov		esi, pPal
			mov		edi, pDst
_r32bn_loop_fw:
			mov		edx, [eax+0]
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+ 0], ecx
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+ 4], ecx
			movzx		ecx, dl
			shr		edx, 8
			mov		ecx, [esi+ecx*4]
			mov		edx, [esi+edx*4]
			mov		[edi+ 8], ecx
			mov		[edi+12], edx

			mov		edx, [eax+4]
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+16], ecx
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+20], ecx
			movzx		ecx, dl
			shr		edx, 8
			mov		ecx, [esi+ecx*4]
			mov		edx, [esi+edx*4]
			mov		[edi+24], ecx
			mov		[edi+28], edx

			lea		eax, [eax+ 8]
			lea		edi, [edi+32]

			sub		width, 8
			jg		_r32bn_loop_fw
		}

			pScn += RENDER_W;
			pDst += pitch;
	}//for( int i = 0; i < SCREEN_HEIGHT; i++ )

	SDL_UnlockSurface(g_screen);
}

void	Render16bpp_Normal( unsigned char* lpRdr)
{
	unsigned char*	pScn = lpRdr;
	unsigned char*	pDst = (unsigned char*)g_screen->pixels;
	unsigned char*	pPal;
	unsigned char*	pColormode =LineColormode;
	unsigned int	width;
	unsigned int	pitch = g_screen->pitch;

	for( int i = 0; i < SCREEN_H; i++ ) {
		if( !(pColormode[i]&0x80) ) {
			pPal = (unsigned char*)CPalette[pColormode[i]&0x07];
		} else {
			pPal = (unsigned char*)MPalette[pColormode[i]&0x07];
		}

		width = SCREEN_W;

		__asm {
			mov		eax, pScn
			mov		esi, pPal
			mov		edi, pDst
_r16bn_loop_fw:
			mov		edx, [eax+0]
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+ 0], cx
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+ 2], cx
			movzx		ecx, dl
			shr		edx, 8
			mov		ecx, [esi+ecx*4]
			mov		edx, [esi+edx*4]
			mov		[edi+ 4], cx
			mov		[edi+ 6], dx

			mov		edx, [eax+4]
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+ 8], cx
			movzx		ecx, dl
			mov		ecx, [esi+ecx*4]
			shr		edx, 8
			mov		[edi+10], cx
			movzx		ecx, dl
			shr		edx, 8
			mov		ecx, [esi+ecx*4]
			mov		edx, [esi+edx*4]
			mov		[edi+12], cx
			mov		[edi+14], dx

			lea		eax, [eax+ 8]
			lea		edi, [edi+16]

			sub		width, 8
			jg		_r16bn_loop_fw
		}

			pScn += RENDER_W;
			pDst += pitch;
	}
}

void Set_attr(unsigned char addr, unsigned char val){
	int nt_row, nt_col;
	int i;
	unsigned int *ptbl, *pval,v;
	int bottom= (addr&0x70)==0x70;
	int tr=bottom?2:4;

	Ntattrib[addr]=val;

	nt_row =(addr>>4)<<2;
	nt_col =(addr&0xf)<<2;
	if (addr>=0x80)
		nt_row -=2;
	ptbl =&Nametbl[nt_row*64+nt_col];

	for (i=0; i<tr; i++){
		pval=&ptbl[((i>>1)<<7)+((i&1)<<1)];
		v =((val)>>(i<<1))<<30;
		*pval= ((*pval) & 0x3fffffff) | v;
		pval=&ptbl[((i>>1)<<7)+((i&1)<<1)+1];
		*pval= ((*pval) & 0x3fffffff) | v;
		pval=&ptbl[((i>>1)<<7)+64+((i&1)<<1)];
		*pval= ((*pval) & 0x3fffffff) | v;
		pval=&ptbl[((i>>1)<<7)+64+((i&1)<<1)+1];
		*pval= ((*pval) & 0x3fffffff) | v;
	}
}

void Write_V(unsigned char c){
	int vinc;

	if (V_inc_mode==1){
		if (V_addr>=0x2000 && V_addr<0x3000){
			vinc=0x40;
		}
		else
			vinc=0x20;
	}else{
			vinc=1;
	}

	if (V_addr<0x2000){//VROM
		Vrom[V_addr]=c;
	}else if (V_addr<0x3000){//NAMETABLE
		*((unsigned char*)(&Nametbl[V_addr-0x2000]))=c;
	}else if(V_addr>=0x3000 && V_addr<0x3100){//ATTR
		Set_attr(V_addr-0x3000, c);
	}else if (V_addr>=0x3f00 && V_addr<0x3f10){
		Bgpal[V_addr-0x3f00]=c;
	}else if (V_addr>=0x3f10 && V_addr<0x3f20){
		Sppal[V_addr-0x3f10]=c;
	}
	V_addr += vinc;
}
