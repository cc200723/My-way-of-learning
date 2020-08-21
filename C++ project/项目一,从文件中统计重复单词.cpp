#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/*
��Ŀһ:ͳ��Ӣ���ĵ����ظ���������ǰ1000������,���ظ������Ӵ�С���,�����浽�ļ�

 sprintf();
*/

#define WORD_LEN 100//һ�ε��ʵ���󳤶�
#define INIT_SIZE 10

typedef struct Word
{
	char str[WORD_LEN];//����
	int count;//���ʳ��ֵĴ���
}Word;

typedef struct WordTable
{
	Word *elem;//ָ��̬����
	int usedsize;//��Ч���ݸ���
	int len;//�ܸ�����
}WordTable;

void InitWordTable(WordTable *pwt)
{
	assert(pwt != NULL);
	pwt->elem = (Word *)malloc(sizeof(Word)*INIT_SIZE);
	pwt->usedsize = 0;
	pwt->len = INIT_SIZE;
}

//��pwt�в���newWord,�ɹ������±�,ʧ�ܷ���-1
int Search(WordTable *pwt,const char *newWord)
{
	for(int i=0;i<pwt->usedsize;i++)//����pwt�е���Ч����
	{
		if(strcmp(pwt->elem[i].str,newWord) == 0)//���ҳɹ�
		{
			return i;
		}
	}
	return -1;
}

//��newWord��ӵ�pwt��
//����β��,����newWord�Ƿ���pwt�н����ж�
bool InsertWord(WordTable *pwt,const char *newWord)
{
	if(pwt->usedsize == pwt->len)//����,��������ԭ����2��
	{
		pwt->len *= 2;//�ܸ�����
		pwt->elem = (Word *)realloc(pwt->elem,pwt->len*sizeof(Word));//�ڴ�����
		//pwt->usedsize;//����
	}

	strcpy(pwt->elem[pwt->usedsize].str,newWord);//���µ���β�嵽elem��
	pwt->elem[pwt->usedsize].count = 1;

	pwt->usedsize++;

	return true;
}

void SaveWord(WordTable *pwt,const char *newWord)
{
	int i = Search(pwt,newWord);
	if(i != -1)//�õ����Ѿ����ֹ�
	{
		pwt->elem[i].count++;
	}
	else//�õ������µ���,��Ҫ��ӵ�pwt��
	{
		InsertWord(pwt,newWord);
	}
}

//���ٶ�̬�ڴ�
void Destroy(WordTable *pwt);

//����
//�������ظ�����count��������
void BubbleSort(WordTable *pwt)
{
	Word tmp;
	for(int i=0;i<pwt->usedsize-1;i++)
	{
		for(int j=0;j+1<pwt->usedsize-i;j++)
		{
			if(pwt->elem[j].count < pwt->elem[j+1].count)
			{
				tmp = pwt->elem[j];
				pwt->elem[j] = pwt->elem[j+1];
				pwt->elem[j+1] = tmp;
			}
		}
	}
}


//���浽�ļ�
//��pwt��ǰlen�����ݱ��浽path�ļ���
void WriteFile(WordTable *pwt,int len)
{
	const char *path = "temp.txt";
	assert( pwt!=NULL && len>0);
	len = len < pwt->usedsize ? len : pwt->usedsize;
	FILE *fw = fopen(path,"w");
	assert(fw != NULL);
	char arr[WORD_LEN+20];

	for(int i=0;i<len;i++)
	{
		sprintf(arr,"%s���ֵĴ���:%d\n",pwt->elem[i].str,pwt->elem[i].count);
		fwrite(arr,sizeof(char),strlen(arr),fw);
	}

	fclose(fw);
}

//���
void Show(WordTable *pwt)
{
	int len = pwt->usedsize<1000 ? pwt->usedsize : 1000;
	for(int i=0;i<len;i++)
	{
		printf("%s���ֵĴ���:%d\n",pwt->elem[i].str,pwt->elem[i].count);
	}
}


//���ļ��ж�ȡ����
void ReadWord(const char *path)
{
	FILE *fr = fopen(path,"r");//����
	assert(fr != NULL);
	char ch;
	char newWord[WORD_LEN];//��ŵ�ǰ��ȡ�ĵ���
	int i = 0;//word�±�
	bool flg = false;//����Ƿ����µ�����Ҫ����
	WordTable wt;
	InitWordTable(&wt);

	while(fread(&ch,sizeof(char),1,fr) > 0)//������Ҫ�Ľ��ĵط�
	{
		if(isalpha((unsigned char)ch))//��ĸ�ַ��ǵ��ʵ�һ����
		{
			newWord[i++] = ch;
			flg = true;
		}
		else //����ĸ�ַ�
		{
			if(flg)//���µ�����Ҫ����
			{
				//todo,
				newWord[i] = '\0';
				SaveWord(&wt,newWord);//������word���浽arr��,��������Ѿ��������������++,�����������
				flg = 0;
				i = 0;
			}
		}
	}
	
	fclose(fr);

	BubbleSort(&wt);
	WriteFile(&wt,1000);
	//Show(&wt);
}


int main()
{
	ReadWord("Harry Poter.txt");
	//int a = 10;
	//double b = 23.4;
	//char *c = "hello";
	//char buf[100];//"23.4000"
	////printf("%d,%f,%s\n",a,b,c);
	//sprintf(buf,"%f",b);
	//printf("buf=%s\n",buf);

	return 0;
}