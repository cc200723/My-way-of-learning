#ifndef GRAPHICS_H
#define GRAPHICS_H

#define SCREEN_W 256
#define SCREEN_H 240
//256+16
#define RENDER_W 272

//(0-7, RGBǿ��ֵ)
#define	BGCOLOR_BIT 0xE0
//(0=��ɫ, 0x80=�ڰ�)
#define	COLORMODE_BIT 0x01
//(0=����ʾ����, 1=��ʾ)
#define BGDISP_BIT 0x10
#define SPDISP_BIT 0x8
#define SP16_BIT 0x4

//SP����λ
#define	SP_VMIRROR_BIT		0x80
#define	SP_HMIRROR_BIT		0x40
#define	SP_PRIORITY_BIT		0x20
#define	SP_COLOR_BIT		0x03

//FCӲ����ɫ����ṹ
typedef	struct	tagPALBUF {
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
} PALBUF, *LPPALBUF;

typedef	struct	tagSPRITE {
	int	y;
	int	tile;
	int	attr;
	int	x;
} SPRITE;

extern unsigned char vcontol;
extern short Scrollx, Scrolly;//(0-511);
extern unsigned char Vrom[8192];
extern unsigned int Nametbl[64*60];;
extern unsigned char Bgpal[256];
extern unsigned char Sppal[256];
extern SPRITE Spram[64];
extern unsigned short V_addr;
extern int V_inc_mode;

extern int framerate;

void CalcPaletteTable();
int initVedeo(int fullscreen);
void DrawBG();
void nesBlit();
void Set_attr(unsigned char addr, unsigned char val);
void Write_V(unsigned char c);

#endif
