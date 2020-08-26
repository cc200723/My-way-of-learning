/*

  timing.cpp

*/

#include <windows.h>
#include <stdio.h>
#include "timing.h"

static LARGE_INTEGER oldt;
static __int64 oneframe;
static unsigned char rand8;

//��ʼ��ʱ�����
//	ȡ�ø߾��ȼ�����Ƶ��
//	����ÿ֡����ĸ߾��ȼ���
//	��һ֡�ĸ߾��ȼ��� =�ָ߾��ȼ���
int init_timer(int frate)
{
	LARGE_INTEGER pfq;
	__int64 pfq64;
	BOOL rv;

	// check for high precision timer

	rv=QueryPerformanceFrequency(&pfq);
	if (rv==0)
		return 0;

	pfq64=pfq.QuadPart;
	oneframe=pfq64/frate;

	rv=QueryPerformanceCounter(&oldt);
	if (rv==0)
		return 0;

	return 1;
}

//����Ϊ60֡/��
void trim_speed()
{
	LARGE_INTEGER curt;
	__int64 curt64,oldt64;
	
	//��ȡ�߾��ȼ��������ּ���
	QueryPerformanceCounter(&curt);
	curt64=curt.QuadPart;
	//ȡ����һ֡�ĸ߾��ȼ���
	oldt64=oldt.QuadPart;

	rand8 =(unsigned char) (curt64 &0xff);

	//�ȴ���ֱ�� �ּ���-��һ֡���� �ﵽ ÿ֡����ļ���
	while ((curt64-oldt64)<oneframe)
	{
		QueryPerformanceCounter(&curt);
		curt64=curt.QuadPart;
	}

	//���� ��һ֡����=�ּ���
	oldt=curt;
}

unsigned char get_rand8(){
	return rand8;
}

