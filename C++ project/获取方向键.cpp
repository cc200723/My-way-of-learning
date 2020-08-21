#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
/*********************************************************************************************************
** Function name:           GetButton
** Descriptions:               获取到方向键的值
** input parameters:       arr   :保存数据的数组                          
** Returned value:          方向键值，1左,2上,3右,4下
**
** Created by:                 hehonghong
** Created Date:             
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Descriptions:
**
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#define KEY_UP 72                                                                 /*  方向键'上'的扫描码码值     */
#define KEY_DOWN 80                                                          /*  方向键'下'的扫描码码值     */
#define KEY_LEFT  75                                                             /*  方向键'左'的扫描码码值     */
#define KEY_RIGHT 77                                                           /*  方向键'右'的扫描码码值     */
int GetButton()
{
	int ch;
	while(1)
	{
		if(_kbhit() != 0)
		{
			ch = _getch();
			if(ch ==  0xE0)
			{
				ch = _getch();
				switch(ch)
				{
				case KEY_LEFT:
					return 1;
				case KEY_UP:
					return 2;
				case KEY_RIGHT:
					return 3;
				case KEY_DOWN:
					return 4;
				default:
					break;
				}
			}
		}
		Sleep(100);                                                                /*避免系统忙等待,降低CPU使用率*/
	}
	return 0;
}

int main()
{
	int a = GetButton();
	if(a == 1)
	{
		printf("你按的是向左键\n");
	}
	else if(a == 2)
	{
		printf("你按的是向上键\n");
	}
	else if(a == 3)
	{
		printf("你按的是向右键\n");
	}
	else
	{
		printf("你按的是向下键\n");
	}
	return 0;
}