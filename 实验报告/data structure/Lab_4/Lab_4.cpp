#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ERROR 0
using namespace std;
/* 
#define MAXSIZE 10
typedef struct{
	int data[MAXSIZE];
	int front,rear; 
}CSeQueue;
//���еĳ�ʼ�� 
CSeQueue *Init_Queue(){
	CSeQueue *q;
	q = (CSeQueue *)malloc(sizeof(CSeQueue));
	q->front = q->rear = 0;
	return q;
}
//�ж��� 
int Full_Queue(CSeQueue *q){
if((q ->rear + 1) % MAXSIZE == q ->front){
	return 1;
}else
return 0;
}

//���
int In_Queue(CSeQueue *q,int x){
if(Full_Queue(q)){	
printf("����");
return 0;
}
else{
	q ->rear = (q ->rear + 1) % MAXSIZE;
	q ->data[q ->rear] = x;
	return 1;
}
}

// �жӿ�
 int Empty_Queue(CSeQueue *q){
 	if(q ->front == q ->rear)
 	return 1;
 	else 
 	return 0;
 }
 
//����
int Out_Queue(CSeQueue *q,int *x){
	if(Empty_Queue(q)){
		printf("�ӿ�");
		return 0;
	}else {
		q ->front = (q ->front + 1) % MAXSIZE;
		*x = q ->data[q ->front];
		return 1;
	}
	
} 
 
//��ӡ��������е�Ԫ�� 
void printf_Queue(CSeQueue *q){
 	int i = q ->front;
 	printf("�����е�Ԫ����:");
 	while(i != q ->rear){
 		printf("%d ",q ->data[i+1]);
 		i ++;
 		i = i % MAXSIZE;
	 }
 }
 
 //����еĳ��� 
 int Queue_Length(CSeQueue *q){
	return(q->rear - q->front + MAXSIZE) % MAXSIZE;
}
 
 int main(){
 	//���г�ʼ�� 
 	CSeQueue *q;
 	q = Init_Queue();
 	//�����һ��Ԫ�� 
    printf("��Ԫ��1���뵽��β��Ľ��:\n");
	In_Queue(q,1);    
    printf_Queue(q);  
    printf("ѭ�����г���=%d\n",Queue_Length(q));
//	����ڶ���Ԫ�� 
	printf("��Ԫ��2���뵽��β��Ľ��:\n");
	In_Queue(q,2);
    printf_Queue(q);  
	printf("ѭ�����г���=%d\n",Queue_Length(q));
//	���������Ԫ�� 
	printf("��Ԫ��3���뵽��β��Ľ��:\n");
	In_Queue(q,3);
    printf_Queue(q);  
	printf("ѭ�����г���=%d\n",Queue_Length(q));
//	ɾ����һ��Ԫ�� 
	int a;
	Out_Queue(q,&a);
	printf("���ӵ�Ԫ����:%d\n",a);
	printf_Queue(q);  
	printf("ѭ�����г���=%d\n",Queue_Length(q));
	
} 
*/
 
 /* 
typedef int ElemType;
typedef struct Queue{
	struct Queue*next;
	int data;
}ListQueue;				//�ӿ� 
struct Queue*front=NULL;//ָ�������Ԫ�ڵ��ָ�� 
struct Queue*rear=NULL;//ָ�����β�ڵ��ָ�� 
int length=0;			//���ƶ��г��ȣ�Ϊ�˷����һ����� 
ListQueue *createQueue() //��ʼ�� 
{
	ListQueue *s=(ListQueue *)malloc(sizeof(ListQueue));
	if(!s)
	{
		printf("�ڴ����ʧ�ܣ�");
		exit(ERROR);
	}
	s->next=NULL;
	length++;
	return s;	
}
void PushQueue(ListQueue *s) //��� 
{
	
	ListQueue *p=(ListQueue*)malloc(sizeof(ListQueue));
	if(!p)				//����ʧ�� 
	{
		printf("�ڴ����ʧ�ܣ�");
		exit(ERROR);       
	}
	printf("��������Ҫ�����ݣ�");
	int a;
	scanf("%d",&a);
	p->data=a;
	p->next=NULL;
	if(length==1) //��һ����� 
	{
		front=rear=p;
		s->next=front;
	}
	else    //��n+1����ӣ�n>=1) 
	{
	    rear->next=p;
		rear=p;
	}
	length++;   //�����Ƿ�Ϊ��һ����ӣ���ʼ��ʱlength�Ѿ�Ϊ1�� 
}
void PopQueue(ListQueue*s) //���� 
{
	if(front==NULL||rear==NULL)
	printf("�ö����ѿգ�");
	int v;
	v=front->data;
	s->next=front->next;
	free(front);
	front=s->next;
	printf("�ó��ӵ�����Ϊ��");
	printf("%d",v);
}
void Display(ListQueue*s) //�������� 
{
	ListQueue*v=s->next;
	while(v)
	{
		printf("%d->",v->data);
		v=v->next;
	}
}
void DestoryQueue(ListQueue *s) //��ն��в�������ͷ�ڵ� 
{
	ListQueue *v=s->next;
	while(v)
	{
		front=v->next;
		free(v);
		v=front;
	}
	printf("�ö�������գ�");
	free(s);
	printf("\n");
	printf("ͷ�ڵ��ͷųɹ���"); 
}
int main()
{
	ListQueue *t=createQueue();
	PushQueue(t);
	PushQueue(t);
	PushQueue(t);
	printf("����������");
	Display(t);
	printf("\n");
	printf("���ӣ�");
	PopQueue(t);
	printf("\n");
	printf("�����������£�");
	printf("\n");
	Display(t);
	printf("\n");
	DestoryQueue(t);
	return 0;
}
*/

//������нṹ 

#define MAXSIZE 100
typedef struct 
{
	int data[MAXSIZE];
	int front,rear;
}SeqQueue,*PSeqQueue;

//��ʼ�� 
PSeqQueue Init_SeqQueue()
{
	PSeqQueue Q;
	Q=(PSeqQueue)malloc(sizeof(SeqQueue));
	if(Q)
	{
		Q->front=0;
		Q->rear=0;
	}
	return Q;
}

//�п� 
int Empty_SeqQueue(PSeqQueue Q)
{
   if(Q&&Q->front==Q->rear)
	   return 1;
   else
	   return 0;
}

//���Ӳ���
int In_SeqQueue(PSeqQueue Q,int x)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		printf("������");
		return 0;
	}
	else
	{
		Q->rear=(Q->rear+1)%MAXSIZE;
		Q->data[Q->rear]=x;
		return 1;
	}
}

//���Ӳ���
int Out_SeqQueue(PSeqQueue Q,int *x)
{
	if(Empty_SeqQueue(Q))
	{
		printf("�ӿգ�");
		return 0;
	}
	else
	{
		Q->front=(Q->front+1)%MAXSIZE;
		*x=Q->data[Q->front];
		return 0;
	}
}

//ȡ��ͷԪ��
int Front_SeqQueue(PSeqQueue Q,int *x)
{
	if(Q->front==Q->rear)
	{
		printf("�ӿգ�");
		return -1;
	}
	else
	{
		*x=Q->data[Q->front+1]%MAXSIZE;
		return 1;
	}
}

//���ٶ���
void Destroy_SeqQueue(PSeqQueue *Q)
{
	if(*Q)
		free(*Q);
	*Q=NULL;
}

 void yanghui_trangle(int n)
{
	PSeqQueue Q;
	Q=(PSeqQueue)malloc(sizeof(SeqQueue));
	if(Q)
	{
		Q->front=0;
		Q->rear=0;
	}
	In_SeqQueue(Q,1);
	In_SeqQueue(Q,1);//
	int i;
	for(i=1;i<=n;i++)
	{
	   printf("\n");
	   for(int k=0;k<=40-4*i;k+=2)
		   printf(" ");//���������ʽ
	   In_SeqQueue(Q,0);
	   int t;
	   int s=0;
	   for(int j=1;j<=i+2;j++)
	   {
		   Out_SeqQueue(Q,&t);
		   In_SeqQueue(Q,s+t);//��ǰ����ĺͷ����β
		   s=t;
		   if(j!=i+2)
			   printf("%4d",s);//����0��ʱ�������������һ��
	   }
	}
	printf("\n");
	Destroy_SeqQueue(&Q);
}
int main()
{
	printf("������Ҫ��ӡ������Ǽ��У�");
	int n;
	scanf("%d",&n);
	yanghui_trangle(n);
	return 0;
}
