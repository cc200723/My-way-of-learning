#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/*
项目一:统计英文文档中重复次数最多的前1000个单词,按重复次数从大到小输出,并保存到文件

 sprintf();
*/

#define WORD_LEN 100//一次单词的最大长度
#define INIT_SIZE 10

typedef struct Word
{
	char str[WORD_LEN];//单词
	int count;//单词出现的次数
}Word;

typedef struct WordTable
{
	Word *elem;//指向动态数组
	int usedsize;//有效数据个数
	int len;//总格子数
}WordTable;

void InitWordTable(WordTable *pwt)
{
	assert(pwt != NULL);
	pwt->elem = (Word *)malloc(sizeof(Word)*INIT_SIZE);
	pwt->usedsize = 0;
	pwt->len = INIT_SIZE;
}

//在pwt中查找newWord,成功返回下标,失败返回-1
int Search(WordTable *pwt,const char *newWord)
{
	for(int i=0;i<pwt->usedsize;i++)//遍历pwt中的有效数据
	{
		if(strcmp(pwt->elem[i].str,newWord) == 0)//查找成功
		{
			return i;
		}
	}
	return -1;
}

//将newWord添加到pwt中
//利用尾插,不对newWord是否在pwt中进行判断
bool InsertWord(WordTable *pwt,const char *newWord)
{
	if(pwt->usedsize == pwt->len)//判满,容量扩大到原来的2倍
	{
		pwt->len *= 2;//总格子数
		pwt->elem = (Word *)realloc(pwt->elem,pwt->len*sizeof(Word));//内存扩大
		//pwt->usedsize;//不变
	}

	strcpy(pwt->elem[pwt->usedsize].str,newWord);//将新单词尾插到elem中
	pwt->elem[pwt->usedsize].count = 1;

	pwt->usedsize++;

	return true;
}

void SaveWord(WordTable *pwt,const char *newWord)
{
	int i = Search(pwt,newWord);
	if(i != -1)//该单词已经出现过
	{
		pwt->elem[i].count++;
	}
	else//该单词是新单词,需要添加到pwt中
	{
		InsertWord(pwt,newWord);
	}
}

//销毁动态内存
void Destroy(WordTable *pwt);

//排序
//按单词重复次数count降序排列
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


//保存到文件
//将pwt的前len个数据保存到path文件中
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
		sprintf(arr,"%s出现的次数:%d\n",pwt->elem[i].str,pwt->elem[i].count);
		fwrite(arr,sizeof(char),strlen(arr),fw);
	}

	fclose(fw);
}

//输出
void Show(WordTable *pwt)
{
	int len = pwt->usedsize<1000 ? pwt->usedsize : 1000;
	for(int i=0;i<len;i++)
	{
		printf("%s出现的次数:%d\n",pwt->elem[i].str,pwt->elem[i].count);
	}
}


//从文件中读取单词
void ReadWord(const char *path)
{
	FILE *fr = fopen(path,"r");//读打开
	assert(fr != NULL);
	char ch;
	char newWord[WORD_LEN];//存放当前读取的单词
	int i = 0;//word下标
	bool flg = false;//标记是否有新单词需要处理
	WordTable wt;
	InitWordTable(&wt);

	while(fread(&ch,sizeof(char),1,fr) > 0)//首先需要改进的地方
	{
		if(isalpha((unsigned char)ch))//字母字符是单词的一部分
		{
			newWord[i++] = ch;
			flg = true;
		}
		else //非字母字符
		{
			if(flg)//有新单词需要处理
			{
				//todo,
				newWord[i] = '\0';
				SaveWord(&wt,newWord);//将单词word保存到arr中,如果单词已经存在则其计数器++,不存在则添加
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