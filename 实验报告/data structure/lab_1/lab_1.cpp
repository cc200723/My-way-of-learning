
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define  INIT_SIZE   100  /*顺序表初始长度分配量*/ 
#define  INCREMENT   10   /* 顺序表存储分配量增量*/
#define  OK     1
#define  ERROR  0

typedef  int  Elemtype;//数据类型重定义 
typedef  int  Status;//状态类型重定义 
typedef struct{
	Elemtype *elem;//元素存储空间基地址 
	int length;//表的当前长度 
	int listsize;//表的初始分配存储容量 
}SqList;

Status InitList_Sq(SqList *L);//顺序表的初始化 
void InputList_Sq(SqList *L);//顺序表数据的输入
Status InsertList_Sq(SqList *L,int i, Elemtype e);//顺序表L的插入
Status ListDelet_Sq(SqList *L,int i, Elemtype *e);//顺序表删除操作
Status LocateElem_Sq(SqList *L,Elemtype e);//顺序表按值查找，成功返回它的序位
Status GetElem_Sq(SqList *L,int i,Elemtype *e);//读取顺序表的元素
void Display_Sq(SqList *L); //顺序表的输出函数 

Status InitList_Sq(SqList *L)//顺序表的初始化 
{
	L->elem=(Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));
	//给表分配初始元素存储容量 
	if(!L->elem)//异常判断 
	{
		return ERROR;
	}
	L->length=0;//初始化表的当前长度为0 
	L->listsize=INIT_SIZE;//初始化表的分配存储容量为 INIT_SIZE  
	
	return OK; 
}

void InputList_Sq(SqList *L)//顺序表数据的输入
{
	int i,n;
	printf("输入顺序表的长度：");
	scanf("%d",&n);
	while(n>L->listsize)
	{
		printf("超出存储空间！重新输入：");
		scanf("%d",&n);
	}
	L->length=n;
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个元素的值：",i); 
		scanf("%d",&L->elem[i]);
	}
}

/*顺序表L的插入，在第i个位置前插入新的元素e,成功返回1，否则返回0*/
Status InsertList_Sq(SqList *L,int i, Elemtype e)
{
	int j;
	Elemtype *NewSpace;
	//插入位置不合法 
	if(i<1||i>L->length)
	{
		return ERROR;
	}
	
	/*................异常判断，插入后如果发生溢出现象，增加内存分配............................*/
	if(L->length>=L->listsize)  
	{   
	    /* realloc扩容后，系统会自动释放掉L->elem存储空间*/ 
		NewSpace=(Elemtype*)realloc(L->elem,(L->listsize+INCREMENT)*sizeof(Elemtype));
		if(!NewSpace)                                    //分配失败
		{                                       
			return ERROR;
		}
		L->elem=NewSpace;                               //获得新的内存分配 
		L->listsize+=INCREMENT;                        //重分配后的存储容量 
	}
	/*....................................................................................*/

	for(j=L->length;j>=i;j--) //i位后的元素往后移动
	{
		L->elem[j]=L->elem[j-1];
	}
	L->elem[j]=e;//插入操作
	L->length++;//表长加一
	return OK;
} 

/*顺序表删除操作，删除表中第i位的元素，并返回删除删除元素的值*/ 
Status ListDelet_Sq(SqList *L,int i, Elemtype *e)
{
	int j;
	if(i<1||i>L->length)//删除位置不存在 
	{
		return ERROR;
	}
	*e=L->elem[i-1];//返回删除元素的值 
	for(j=i;j<L->length;j++)//删除操作 
	{
		L->elem[j-1]=L->elem[j];
	}
	L->length--;//表长减一
	return OK;
}

/*顺序表按值查找，成功返回它的序位，否则返回-1*/ 
Status LocateElem_Sq(SqList *L,Elemtype e)
{
	int i;
	for(i=0;i<L->length;i++)
	{
		if(L->elem[i]==e)
		return i;
	}
	return -1;
} 

/*读取顺序表的元素*/
Status GetElem_Sq(SqList *L,int i,Elemtype *e)
{
	if(i<1||i>L->length)
	{
		return ERROR;
	}
	*e=L->elem[i-1];
	return OK;
}

//顺序表的输出函数 
void Display_Sq(SqList *L) 
{
	int i;
	for(i=0;i<L->length;i++)
	{
		printf("%d ",L->elem[i]);
	}
	printf("\n");
}

int main()
{
	int n,num,e,value;
	SqList L;
	
	/*顺序表初始化和输入*/
	value=InitList_Sq(&L);
	if(value)
	{
		printf("线性表初始化成功！\n");
	}
	else
	{
		printf("线性表初始化失败！\n");
		return ERROR; 
	}
	InputList_Sq(&L);
	printf("顺序表各元素的值为："); 
	Display_Sq(&L);	

	
	/*顺序表插入*/
	printf("\n请输入插入位置："); 
	scanf("%d",&n);
	printf("请输入插入元素：");
    scanf("%d",&num); 
	value=InsertList_Sq(&L,n,num);
	if(value)
	{
		printf("进行插入操作后线性表依次为：\n");
		Display_Sq(&L);	
	}
	else
	{
		printf("插入失败！");
		return ERROR;
	} 
	
   /*顺序表删除*/
	printf("\n请输入删除位置：");
	scanf("%d",&n);
	value=ListDelet_Sq(&L,n,&e);
	if(value)
	{
		printf("被删除的元素为：%d\n",e);
		printf("进行删除操作后线性表依次为：\n");
		Display_Sq(&L);	
	}
	else
	{
		printf("删除失败！\n");
		return ERROR;
	} 
	
	/*顺序表查找*/
	printf("\n请输入要查找的元素值：");
	scanf("%d",&num);
	value=LocateElem_Sq(&L,num);
	if(value>=0) printf("该元素在第%d位\n",value+1);
	else  printf("error!\n");
	
	/*顺序表读取*/
	printf("\n请输入读取元素的位置：");
	scanf("%d",&n); 
	value=GetElem_Sq(&L,n,&e);
	if(value) printf("该元素为：%d\n",e);
	else printf("error!\n");

	return 0;
}
