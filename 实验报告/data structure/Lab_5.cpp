#include <iostream>
#define MAXSIZE 100
using namespace std;
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

void InOrderTraverse1(BiTree T) {
	//先序遍历
	if(T) {
		cout<<T->data;
		InOrderTraverse1(T->lchild);
		InOrderTraverse1(T->rchild);
	}
}
 
void InOrderTraverse2(BiTree T) {
	//中序遍历
	if(T) {
		InOrderTraverse2(T->lchild);
		cout<<T->data;
		InOrderTraverse2(T->rchild);
	}
}
void InOrderTraverse3(BiTree T) {
	//后序遍历
	if(T) {
		InOrderTraverse3(T->lchild);
		InOrderTraverse3(T->rchild);
		cout<<T->data;
	}
}
void CreateBiTree(BiTree &T) {
	//先序
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
	cout<<"请输入二叉树的元素!\n";
	CreateBiTree(a);
	cout<<"按先序遍历法输出该二叉树的元素为：\n";
	InOrderTraverse1(a);
    cout<<"\n按中序遍历法输出该二叉树的元素为：\n"; 
	InOrderTraverse2(a);
	cout<<"\n按后序遍历法输出该二叉树的元素为：\n"; 
	InOrderTraverse3(a);
	height=Depth(a);
	num=NodeCount(a);
	leafnum= LeafNum(a);
	cout<<"\n该二叉树高度为："; 
	cout<<height<<endl;
	cout<<"该二叉树结点数为："; 
	cout<<num;
	cout<<"该二叉树叶子结点数为："; 
	cout<<leafnum;
	return 0;
}
