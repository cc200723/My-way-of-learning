#include <iostream>
#define MAXSIZE 100
using namespace std;
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

void InOrderTraverse1(BiTree T) {
	//�������
	if(T) {
		cout<<T->data;
		InOrderTraverse1(T->lchild);
		InOrderTraverse1(T->rchild);
	}
}
 
void InOrderTraverse2(BiTree T) {
	//�������
	if(T) {
		InOrderTraverse2(T->lchild);
		cout<<T->data;
		InOrderTraverse2(T->rchild);
	}
}
void InOrderTraverse3(BiTree T) {
	//�������
	if(T) {
		InOrderTraverse3(T->lchild);
		InOrderTraverse3(T->rchild);
		cout<<T->data;
	}
}
void CreateBiTree(BiTree &T) {
	//����
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else {
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
int Depth(BiTree T) {
	int n,m;
	if(T==NULL)
		return 0;
	else {
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return(m+1);
		else
			return(n+1);
	}
}
int NodeCount(BiTree T) {
	if(T==NULL)
		return 0;
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int LeafNum(BiTree T) {
	if (!T) {
		return 0;
	} else if (!T->lchild && !T->rchild) {
		return 1;
	} else {
		return LeafNum(T->lchild) + LeafNum(T->rchild);
	}
}



int main() 
{
	BiTree a;
	int height,num,leafnum;
	cout<<"�������������Ԫ��!\n";
	CreateBiTree(a);
	cout<<"���������������ö�������Ԫ��Ϊ��\n";
	InOrderTraverse1(a);
    cout<<"\n���������������ö�������Ԫ��Ϊ��\n"; 
	InOrderTraverse2(a);
	cout<<"\n���������������ö�������Ԫ��Ϊ��\n"; 
	InOrderTraverse3(a);
	height=Depth(a);
	num=NodeCount(a);
	leafnum= LeafNum(a);
	cout<<"\n�ö������߶�Ϊ��"; 
	cout<<height<<endl;
	cout<<"�ö����������Ϊ��"; 
	cout<<num;
	cout<<"�ö�����Ҷ�ӽ����Ϊ��"; 
	cout<<leafnum;
	return 0;
}
