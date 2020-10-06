#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef int ElemType;
typedef struct Node  //�ýṹ�嶨����
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;
//��struct Node *����Ϊ������LinkList����һ���ṹ���ָ�롣  

void InitLinkList()   //��ʼ��
{
	Node* L;  //����һ��ͷ���
	L = (Node *)malloc(sizeof(Node));//ͷ��������ַ
	if (L == NULL)
		printf("����ռ�ʧ��");
	L->next = NULL;
}

LinkList CreateLinkedListHead(int n)//ͷ�巨  
{
	int i;
	int x;
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	printf("����Ԫ�أ�");
	for (i = 0; i<n; i++)
	{
		Node *p; //Ҫ����Ľ��
		p = (Node *)malloc(sizeof(Node));
		scanf("%d", &x);
		p->data = x;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

LinkList CreateLinkedListTail(int n)//β�巨  
{
	int x;
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	Node *r;
	r = L;
	printf("����Ԫ��:");
	while (n--)
	{
		scanf("%d", &x);
		Node *p;
		p = (Node *)malloc(sizeof(Node));
		p->data = x;
		r->next = p;
		r = p;//֮���ѭ������r���ǵ�ͬ��p r->next����p->next
	}
	r->next = NULL;
	return L;
}

void InsertLinkList(LinkList L, int i, ElemType x)//����Ԫ��  iΪ����λ�� xΪ����Ԫ��
{
	LinkList p;
	p = L;//�������ͷ��㸳ֵ��p
	int j;
	j = 1;
	while (j<i)
	{
		p = p->next;
		j++;
	}
	Node *s;  //�������Ľ��
	s = (Node *)malloc(sizeof(Node));
	s->data = x;
	s->next = p->next;
	p->next = s;

}

void deleteLinkList(LinkList L, int i)//ɾ��iλ���ϵ�Ԫ��  
{
	int j;
	LinkList p, q;
	p = L;
	j = 1;
	while (j<i)
	{
		p = p->next;
		j++;
	}
	q = p->next;
	p->next = p->next->next;
	free(q);
}

int GetElem(LinkList L, int i)//��ȡԪ��  
{
	ElemType e;
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j<i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("��%d���ڵ㲻����\n", i);
		return 0;
	}
	else 

	e = p->data;
	return e;
}

void ListLocate_L(LinkList L, ElemType e)//��ȡԪ��λ��  
{
    Node *p = L ; 
	int k=0;    
    while(p->next){
    	if(p->data==e){
    		printf("��Ԫ�ص�λ��Ϊ%d\n",k);
    		return;
		}
		else{
			p=p->next;
			k++;
		}
		if(p==L){
			printf("δ�ҵ���Ԫ�أ�\n");
			return;
		
		}
	}	
}
 
int getlength(LinkList L)//��������
{
	LinkList p;
    int length = 0;
	p = L->next;//pָ���һ���ڵ㣻
	   while (p)
	   {
		   printf("�����������Ϊ%d\n", p->data);
		   length++;
		   p = p->next;
		 
    	}
	   return length;
	
}
 
 void output(LinkList L)//������ӡ���� 
{
	Node *p;
	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d", p->data);
	}
}

int main()
{
	int n;
	int i;
	int x;
	LinkList H;
	
	printf("���뵥����ĳ��ȣ�ͷ�巨��:");
	scanf("%d", &n);
	H = CreateLinkedListHead(n);
	output(H);
	printf("\n");
	
	printf("���뵥����ĳ��ȣ�β�巨��:");
	scanf("%d", &n);
	H = CreateLinkedListTail(n);
	output(H);
	printf("\n");
	
	printf("��������Ϊ%d", getlength(H));
	printf("\n");
	
	printf("����Ҫ��ȡ��һλ�õ�Ԫ�أ�");
	scanf("%d", &i);
	printf("%d\n", GetElem(H, i));
	
	printf("����Ҫ��ȡ��һԪ�ص�λ�ã�");
	scanf("%d", &i);
	ListLocate_L(H,i);
	printf("\n");
	
	printf("����Ҫ�����Ԫ��e��λ��i��");
	scanf("%d %d", &x, &i);
	InsertLinkList(H, i, x);
	output(H);
	printf("\n");
	
	printf("����Ҫɾ����һλ���ϵ�Ԫ�أ�");
	scanf("%d", &i);
	deleteLinkList(H, i);
	output(H);
	return 0;
}

