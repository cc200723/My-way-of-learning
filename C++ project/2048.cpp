#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ROW 4
#define COL ROW

#define KEY1           224
#define KEY_LEFT    75
#define KEY_UP       72
#define KEY_RIGHT 77
#define KEY_DOWN 80

int g_sgap = 0;

/*
Ӧ���г�����2048
�����Ҫͼ�ν���,��Ҫ�ӽ����
*/

//������arr����һ���µ�����
void GetNewVal(int arr[ROW][COL])
{
	srand( (unsigned)time( NULL ) + g_sgap++);
	int x = rand()%ROW;//���±�,��֤��Խ��
	int y = rand()%COL;//���±�,��֤��Խ��

	int newval = 2;
	if(x == 0)//75%�ĸ���Ϊ2,25%�ĸ���Ϊ4
	{
		newval = 4;
	}

	//�ҵ����еĸ���
	while(arr[x][y] != 0)//�ø����Ѿ���ֵ,todo�п�����ѭ��
	{
		y++;
		if(y == COL)//
		{
			y = 0;
			x = (x+1)%ROW;//��һ��
		}
	}

	arr[x][y] = newval;
}

//��ӡ
void Show(int arr[ROW][COL])
{
	system("cls");
	for(int i=0; i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
}

//��ʾ��ʼ����
void Start(int arr[ROW][COL])
{
	//��ȡ��������,Ȼ����ʾ����
	GetNewVal(arr);
	GetNewVal(arr);

	Show(arr);
}

//��ȡ��ֵ,��:1,��:2,��:3,��:4,����:0
int GetButton()
{
	int key1 = 0;//��һ����ֵ
	int key2 = 0;//�ڶ�����ֵ
	while(1)
	{
		if(_kbhit())
		{
			key1 = _getch();//��õ�һ����ֵ
			if(key1 == KEY1)//0xE0
			{
				key2 = _getch();//��ȡ�ڶ�����ֵ
				if(key2 == KEY_LEFT)
				{
					return 1;
				}
				else if(key2 == KEY_UP)
				{
					return 2;
				}
				else if(key2 == KEY_RIGHT)
				{
					return 3;
				}
				else if(key2 == KEY_DOWN)
				{
					return 4;
				}
			}
		}
		Sleep(100);//˯��,�ó�CPU,����æ�ȴ�
	}
}

//����ϲ�
bool MergeLeft(int arr[ROW][COL])
{
	int x1 = -1;//��һ����Ҫ�ϲ��������±�
	
	bool flg = false;//��ǰû����Ч�ϲ�(û�����ݺϲ�,Ҳû�������ƶ�)

	for(int i=0;i<ROW;i++)
	{
		x1 = -1;
		//��һ��,�ϲ���ͬ������
		for(int j=0;j<COL;j++)
		{
			if(arr[i][j]!=0)
			{
				if(x1 == -1)//���е�һ����0��ֵ
				{
					x1 = j;
				}
				else//��ǰ�ڶ�����Ҫ�����ֵ
				{
					if(arr[i][j] == arr[i][x1])//�ϲ�,��x1�±��ֵ*2,j�±��ֵ��Ϊ0
					{
						arr[i][x1] *= 2;
						arr[i][j] = 0;
						x1 = -1;
						flg = true;
					}
					else//��һ��ֵ�͵ڶ���ֵ����,
					{
						x1 = j;
					}
				}
			}

		}

		//�ڶ���,�ƶ�����
		int index = 0;//��ǰ���Է����ݵ��±�
		for(int j=0;j<COL;j++)
		{
			if(arr[i][j]!=0)//��Ҫ�ƶ�����
			{
				if(index != j)
				{
					arr[i][index] = arr[i][j];
					arr[i][j] = 0;
					index++;
					flg = true;
				}
				else
				{
					index++;
				}
			}
		}
	}
	return flg;
}

//��Ϸ�Ƿ����
//1.û�п��е�Ԫ��
//2.����û����ͬ������
bool IsGameOver(int arr[ROW][COL])
{
	//�ж���û�п��е�Ԫ��
	int activeCell = 0;//ͳ�ƿ��е�Ԫ������
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(arr[i][j] == 0)
			{
				activeCell++;
			}
		}
	}
	if(activeCell != 0)
	{
		return false;
	}

	//�����Ƿ�����ͬ������,ֻ��Ҫ�ж��ұߺ��±�
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			//if(arr[i][j]==arr[i][j+1] || arr[i][j] == arr[i+1][j])
			if(j+1<COL&&arr[i][j]==arr[i][j+1] || i+1<ROW&&arr[i][j]==arr[i+1][j])
			{
				return false;
			}
		}
	}
	return true;
}

void Run(int arr[ROW][COL])
{
	int bt;
	bool rt = false;
	while(1)
	{
		bt = GetButton();

		if(bt == 1)//�������
		{
			rt = MergeLeft(arr);
			if(rt)
			{
				GetNewVal(arr);
				Show(arr);
				if(IsGameOver(arr))
				{
					return ;
				}
			}
		}
	}

}

int main()
{
	int arr[ROW][COL] = {0};

	Start(arr);

	Run(arr);

	return 0;
}

/*
//��ȡ���̼�ֵ,ͨ���ó�����Եõ�������ļ�ֵ
int main()
{
	int a = 0;
	while(1)
	{
		if(_kbhit())
		{
			a = _getch();//getchar();
			printf("��ֵ��:%d\n",a);
		}
	}
	return 0;
}
*/

/*
int main()
{
	srand( (unsigned)time( NULL ) );


	for(int i=0;i<10;i++)
	{
		printf("%d ",rand());
	}
	printf("\n");

	return 0;
}
*/