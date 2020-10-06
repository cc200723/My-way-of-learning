#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef int ElemType;
typedef struct Node  //用结构体定义结点
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;
//把struct Node *定义为新类型LinkList，是一个结构体的指针。  

void InitLinkList()   //初始化
{
	Node* L;  //定义一个头结点
	L = (Node *)malloc(sizeof(Node));//头结点申请地址
	if (L == NULL)
		printf("申请空间失败");
	L->next = NULL;
}

LinkList CreateLinkedListHead(int n)//头插法  
{
	int i;
	int x;
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	printf("输入元素：");
	for (i = 0; i<n; i++)
	{
		Node *p; //要插入的结点
		p = (Node *)malloc(sizeof(Node));
		scanf("%d", &x);
		p->data = x;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

LinkList CreateLinkedListTail(int n)//尾插法  
{
	int x;
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	Node *r;
	r = L;
	printf("输入元素:");
	while (n--)
	{
		scanf("%d", &x);
		Node *p;
		p = (Node *)malloc(sizeof(Node));
		p->data = x;
		r->next = p;
		r = p;//之后的循环遇到r就是等同于p r->next就是p->next
	}
	r->next = NULL;
	return L;
}

void InsertLinkList(LinkList L, int i, ElemType x)//插入元素  i为插入位置 x为插入元素
{
	LinkList p;
	p = L;//把链表的头结点赋值给p
	int j;
	j = 1;
	while (j<i)
	{
		p = p->next;
		j++;
	}
	Node *s;  //定义插入的结点
	s = (Node *)malloc(sizeof(Node));
	s->data = x;
	s->next = p->next;
	p->next = s;

}

void deleteLinkList(LinkList L, int i)//删除i位置上的元素  
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

int GetElem(LinkList L, int i)//获取元素  
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
		printf("第%d个节点不存在\n", i);
		return 0;
	}
	else 

	e = p->data;
	return e;
}

void ListLocate_L(LinkList L, ElemType e)//获取元素位置  
{
    Node *p = L ; 
	int k=0;    
    while(p->next){
    	if(p->data==e){
    		printf("该元素的位置为%d\n",k);
    		return;
		}
		else{
			p=p->next;
			k++;
		}
		if(p==L){
			printf("未找到该元素！\n");
			return;
		
		}
	}	
}
 
int getlength(LinkList L)//求单链表长度
{
	LinkList p;
    int length = 0;
	p = L->next;//p指向第一个节点；
	   while (p)
	   {
		   printf("单链表的数据为%d\n", p->data);
		   length++;
		   p = p->next;
		 
    	}
	   return length;
	
}
 
 void output(LinkList L)//遍历打印链表 
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
	
	printf("输入单链表的长度（头插法）:");
	scanf("%d", &n);
	H = CreateLinkedListHead(n);
	output(H);
	printf("\n");
	
	printf("输入单链表的长度（尾插法）:");
	scanf("%d", &n);
	H = CreateLinkedListTail(n);
	output(H);
	printf("\n");
	
	printf("单链表长度为%d", getlength(H));
	printf("\n");
	
	printf("输入要获取哪一位置的元素：");
	scanf("%d", &i);
	printf("%d\n", GetElem(H, i));
	
	printf("输入要获取哪一元素的位置：");
	scanf("%d", &i);
	ListLocate_L(H,i);
	printf("\n");
	
	printf("输入要插入的元素e与位置i：");
	scanf("%d %d", &x, &i);
	InsertLinkList(H, i, x);
	output(H);
	printf("\n");
	
	printf("输入要删除哪一位置上的元素：");
	scanf("%d", &i);
	deleteLinkList(H, i);
	output(H);
	return 0;
}

