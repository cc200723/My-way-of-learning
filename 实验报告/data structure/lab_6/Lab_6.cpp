#include<iostream>
#include<cstdio>
#include<cstdlib>
#define max 20
#define SIZE 20
#define MORE 10
typedef struct ArcNode{
	int adjvex; //该弧所指向的顶点的位置
	struct ArcNode *nextarc; //指向下一条弧的指针 
}ArcNode;

typedef struct VNode{
	char data;  //顶点信息
	ArcNode *firstarc; //指向第一条依附该顶点的弧的指针  
}VNode,AdjList[max];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;
 
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;
void InitStack(SqStack &S){
	//构造一个空栈 
	S.base=(int *)malloc(SIZE*sizeof(int));
	if(!S.base) return ;
	S.top=S.base;
	S.stacksize=SIZE;
}
int StackEmpty(SqStack &S){
	//判空 是返回1 否返回0
	if(S.top==S.base) return 1;
	else return 0;	
} 
void Push(SqStack &S,int e){
	//入栈 
	if(S.top-S.base>=S.stacksize){
		S.base=(int *)realloc(S.base,(S.stacksize+MORE)*sizeof(int));
		if(!S.base) exit(0);
		S.top=S.base+S.stacksize;
		S.stacksize+=MORE;
	}
	*S.top++=e;
}
void Pop(SqStack &S,int &e){
	//出栈
	if(S.top==S.base) exit(0);
	else
		e=*--S.top; 
}
void GetTop(SqStack S,int &e){
	//取栈顶元素 
	if(S.top==S.base)  exit(0);
	else
		e=*(S.top-1);
}
void CreatGraph(ALGraph &G){
	int i,s,e;
	ArcNode *p,*q;
	printf("输入结点数目和边数：");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	getchar();
	printf("输入顶点信息：\n");
	for(i=1;i<=G.vexnum;i++){
		scanf("%c",&G.vertices[i].data);
		G.vertices[i].firstarc=NULL;
	} 
	getchar();
	printf("输入一条边依附的起点序号和终点序号：\n");
	for(i=1;i<=G.arcnum;i++){
		scanf("%d%d",&s,&e);
		getchar();
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->nextarc=NULL;
		p->adjvex=e;
		q=G.vertices[s].firstarc;
		if(!q)
			G.vertices[s].firstarc=p;
		else{
			while(q->nextarc){
				q=q->nextarc;
			}
			q->nextarc=p;
		}
	}
}
void PrintGraph(ALGraph G){
	int i;
	printf("打印有向图：\n");
	for(i=1;i<=G.vexnum;i++){
		printf("%3c",G.vertices[i].data);
		if(G.vertices[i].firstarc==NULL){
			printf("\n");
			continue;
		}
		while(G.vertices[i].firstarc){
			printf("%3d",G.vertices[i].firstarc->adjvex);
			G.vertices[i].firstarc=G.vertices[i].firstarc->nextarc;
		}
		printf("\n");
	}
}
int visited1[max];
void Dfs(ALGraph G,int v){
	ArcNode *p;
	int w;
	visited1[v]=1;
	printf("%c",G.vertices[v].data);
	p=G.vertices[v].firstarc;
	while(p){
		w=p->adjvex;
		if(!visited1[w])
			Dfs(G,w);
			p=p->nextarc;
	}
}
void DfsTraverse(ALGraph G){
	//深度优先遍历递归算法 
	int v;
	for(v=1;v<=G.vexnum;v++){
		visited1[v]=0;
	} 
	for(v=1;v<=G.vexnum;v++){
		if(!visited1[v])
			Dfs(G,v);
	}	
}
void DfsTraverse2(ALGraph G,int v){
	//从第v个顶点进行深度优先遍历（非递归） 
	int visited2[max],n,i;
	for(i=1;i<=G.vexnum;i++)
		visited2[i]=0;
	ArcNode *p;
	SqStack S;
	InitStack(S);
	visited2[v]=1;
	printf("%c",G.vertices[v].data);
	Push(S,v);
	while(!StackEmpty(S)){
		GetTop(S,v);
		p=G.vertices[v].firstarc;
		while(p)
			if(visited2[p->adjvex])
				p=p->nextarc;
			else{
				printf("%c",G.vertices[p->adjvex].data);
				visited2[p->adjvex]=1;
				Push(S,p->adjvex);
				p=G.vertices[p->adjvex].firstarc;
			}
		if(!StackEmpty(S)){
			Pop(S,n);
		}
	}
}
int q[max],f=0,r=0;
int visited2[max];
void BfsTraverse(ALGraph G,int s){
	//广度优先遍历的递归算法 
	ArcNode *p;
    if(!visited2[s]){
        printf("%c",G.vertices[s].data);
        visited2[s]=1;
        p=G.vertices[s].firstarc;
        while(p){
            if(!visited2[p->adjvex])
                q[r++]=p->adjvex;
            p=p->nextarc;
        }
    }
    while(f<r){
       BfsTraverse(G,q[f++]);
    }
}
void FindInDegree(ALGraph G,int indegree[]){
	//求顶点入度
	ArcNode *p;
	int i;
	for(i=1;i<=G.vexnum;i++) //初始化
		indegree[i]=0;
	for(i=1;i<=G.vexnum;i++){
		p=G.vertices[i].firstarc;
		while(p){
			indegree[p->adjvex]++;
			p=p->nextarc;
		}
	} 
}
void TopologicalSort(ALGraph G){
	//拓扑排序
	ArcNode *p;
	SqStack S;
	int count;
	int i,k,indegree[max];
	FindInDegree(G,indegree); //求入度 
	InitStack(S);
	for(i=1;i<=G.vexnum;i++)// 将入度为零的点压入栈
		if(!indegree[i]) Push(S,i);
	count=0;
	while(!StackEmpty(S)){
		Pop(S,i);
		printf("%c",G.vertices[i].data);
		count++;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(!(--indegree[k])) Push(S,k);
		}
	}
	if(count<G.vexnum){
		printf("该图有回路\n");
		exit(0);
	}
}
int main(){
	ALGraph G;
	CreatGraph(G);
	PrintGraph(G);
	printf("\nDfs(递归):");
	DfsTraverse(G);
	printf("\nDfs(非递归):");
	DfsTraverse2(G,1);
	printf("\nBfs:");
	BfsTraverse(G,1);
	printf("\n拓扑排序：\n");
	TopologicalSort(G);
	return 0;
}


