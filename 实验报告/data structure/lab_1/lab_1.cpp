
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define  INIT_SIZE   100  /*˳����ʼ���ȷ�����*/ 
#define  INCREMENT   10   /* ˳���洢����������*/
#define  OK     1
#define  ERROR  0

typedef  int  Elemtype;//���������ض��� 
typedef  int  Status;//״̬�����ض��� 
typedef struct{
	Elemtype *elem;//Ԫ�ش洢�ռ����ַ 
	int length;//��ĵ�ǰ���� 
	int listsize;//��ĳ�ʼ����洢���� 
}SqList;

Status InitList_Sq(SqList *L);//˳���ĳ�ʼ�� 
void InputList_Sq(SqList *L);//˳������ݵ�����
Status InsertList_Sq(SqList *L,int i, Elemtype e);//˳���L�Ĳ���
Status ListDelet_Sq(SqList *L,int i, Elemtype *e);//˳���ɾ������
Status LocateElem_Sq(SqList *L,Elemtype e);//˳���ֵ���ң��ɹ�����������λ
Status GetElem_Sq(SqList *L,int i,Elemtype *e);//��ȡ˳����Ԫ��
void Display_Sq(SqList *L); //˳����������� 

Status InitList_Sq(SqList *L)//˳���ĳ�ʼ�� 
{
	L->elem=(Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));
	//��������ʼԪ�ش洢���� 
	if(!L->elem)//�쳣�ж� 
	{
		return ERROR;
	}
	L->length=0;//��ʼ����ĵ�ǰ����Ϊ0 
	L->listsize=INIT_SIZE;//��ʼ����ķ���洢����Ϊ INIT_SIZE  
	
	return OK; 
}

void InputList_Sq(SqList *L)//˳������ݵ�����
{
	int i,n;
	printf("����˳���ĳ��ȣ�");
	scanf("%d",&n);
	while(n>L->listsize)
	{
		printf("�����洢�ռ䣡�������룺");
		scanf("%d",&n);
	}
	L->length=n;
	for(i=0;i<n;i++)
	{
		printf("�������%d��Ԫ�ص�ֵ��",i); 
		scanf("%d",&L->elem[i]);
	}
}

/*˳���L�Ĳ��룬�ڵ�i��λ��ǰ�����µ�Ԫ��e,�ɹ�����1�����򷵻�0*/
Status InsertList_Sq(SqList *L,int i, Elemtype e)
{
	int j;
	Elemtype *NewSpace;
	//����λ�ò��Ϸ� 
	if(i<1||i>L->length)
	{
		return ERROR;
	}
	
	/*................�쳣�жϣ�������������������������ڴ����............................*/
	if(L->length>=L->listsize)  
	{   
	    /* realloc���ݺ�ϵͳ���Զ��ͷŵ�L->elem�洢�ռ�*/ 
		NewSpace=(Elemtype*)realloc(L->elem,(L->listsize+INCREMENT)*sizeof(Elemtype));
		if(!NewSpace)                                    //����ʧ��
		{                                       
			return ERROR;
		}
		L->elem=NewSpace;                               //����µ��ڴ���� 
		L->listsize+=INCREMENT;                        //�ط����Ĵ洢���� 
	}
	/*....................................................................................*/

	for(j=L->length;j>=i;j--) //iλ���Ԫ�������ƶ�
	{
		L->elem[j]=L->elem[j-1];
	}
	L->elem[j]=e;//�������
	L->length++;//����һ
	return OK;
} 

/*˳���ɾ��������ɾ�����е�iλ��Ԫ�أ�������ɾ��ɾ��Ԫ�ص�ֵ*/ 
Status ListDelet_Sq(SqList *L,int i, Elemtype *e)
{
	int j;
	if(i<1||i>L->length)//ɾ��λ�ò����� 
	{
		return ERROR;
	}
	*e=L->elem[i-1];//����ɾ��Ԫ�ص�ֵ 
	for(j=i;j<L->length;j++)//ɾ������ 
	{
		L->elem[j-1]=L->elem[j];
	}
	L->length--;//����һ
	return OK;
}

/*˳���ֵ���ң��ɹ�����������λ�����򷵻�-1*/ 
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

/*��ȡ˳����Ԫ��*/
Status GetElem_Sq(SqList *L,int i,Elemtype *e)
{
	if(i<1||i>L->length)
	{
		return ERROR;
	}
	*e=L->elem[i-1];
	return OK;
}

//˳����������� 
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
	
	/*˳����ʼ��������*/
	value=InitList_Sq(&L);
	if(value)
	{
		printf("���Ա��ʼ���ɹ���\n");
	}
	else
	{
		printf("���Ա��ʼ��ʧ�ܣ�\n");
		return ERROR; 
	}
	InputList_Sq(&L);
	printf("˳����Ԫ�ص�ֵΪ��"); 
	Display_Sq(&L);	

	
	/*˳������*/
	printf("\n���������λ�ã�"); 
	scanf("%d",&n);
	printf("���������Ԫ�أ�");
    scanf("%d",&num); 
	value=InsertList_Sq(&L,n,num);
	if(value)
	{
		printf("���в�����������Ա�����Ϊ��\n");
		Display_Sq(&L);	
	}
	else
	{
		printf("����ʧ�ܣ�");
		return ERROR;
	} 
	
   /*˳���ɾ��*/
	printf("\n������ɾ��λ�ã�");
	scanf("%d",&n);
	value=ListDelet_Sq(&L,n,&e);
	if(value)
	{
		printf("��ɾ����Ԫ��Ϊ��%d\n",e);
		printf("����ɾ�����������Ա�����Ϊ��\n");
		Display_Sq(&L);	
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
		return ERROR;
	} 
	
	/*˳������*/
	printf("\n������Ҫ���ҵ�Ԫ��ֵ��");
	scanf("%d",&num);
	value=LocateElem_Sq(&L,num);
	if(value>=0) printf("��Ԫ���ڵ�%dλ\n",value+1);
	else  printf("error!\n");
	
	/*˳����ȡ*/
	printf("\n�������ȡԪ�ص�λ�ã�");
	scanf("%d",&n); 
	value=GetElem_Sq(&L,n,&e);
	if(value) printf("��Ԫ��Ϊ��%d\n",e);
	else printf("error!\n");

	return 0;
}
