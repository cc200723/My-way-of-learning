#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LIST_INIT_SIZE 100 //初始表空间大小
#define LISTINCREMENT 10 //表长增量
typedef int Status; /**Status是函数类型，其值是函数结果状态代码，如OK等**/
typedef char ElemType; /*ElemType类型根据实际情况而定，这里假设为char*/
/**顺序表的定义**/
typedef struct{
ElemType *elem; /**储存空间基地址**/
int length; /**当前长度**/
int listsize; /**当前分配的储存容量（以sizeof(Elemtype)为单位）**/
}SqList;
 
SqList La,Lb,Lc,Ld; /**定义全局变量**/
 
/**构造一个空的线性表L**/
Status InitList_Sq(SqList &L){
L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
if(!L.elem) exit(OVERFLOW); /**储存分配失败**/
L.length = 0; /**空表长度为0**/
L.listsize = LIST_INIT_SIZE; /**初始储存容量**/
return OK;
} /**该函数的时间复杂度为O(n)**/
 
/**在顺序表的逻辑为i的位置插入新元素e的函数**/
Status ListInsert_Sq(SqList &L,int i,ElemType e){
ElemType *newbase,*p,*q;
//i的合法值为(1 <= i <= L.length_Sq(L) + 1)
//异常处理
if(i < 1 || i > L.length + 1) return ERROR;
if(L.length >= L.listsize){ //当前储存空间已满，增加分配
newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(ElemType));
if(!newbase) exit(OVERFLOW); //储存分配失败
L.elem = newbase; //新基址
L.listsize += LISTINCREMENT; //增加储存容量
}
q = &(L.elem[i - 1]); //q为插入位置
for(p = &(L.elem[L.length - 1]); p >= q; --p) 
*(p + 1) = *p; //插入位置及之后的元素往右移
*q = e; //插入e
++L.length; //表长加1
return OK;
}
 
/**创建一个线性表，即输入数据,根据集合定义：集合中的元素不能相等创建**/
void CreateList_Sq(SqList &L){
ElemType ch;
int inlist = FALSE,j;
while((ch) != '\n'){
scanf("%c",&ch);
for(j = 0; j < L.length; j++)
if(ch == L.elem[j]){
inlist = TRUE;
break;
}
else
inlist = FALSE;
if(!inlist && ch != '\n') ListInsert_Sq(L,L.length+1,ch);
}
}
/**判断两元素是否相等,若相等则返回TRUE;否则返回FALSE**/
Status Equal(ElemType a,ElemType b){
if(a == b) return TRUE;
else return FALSE;
}
 
/**在顺序线性表L中查找第1个与e满足compare()的元素位序，若找到，则返回其在L中的位序，否则返回0**/
int LocateElem_Sq(SqList L,ElemType e,Status(* compare)(ElemType,ElemType)){
ElemType *p;
int i;
i = 1; //i的初值为第1个元素的位序
p = L.elem; //p的初值为第1个元素的储存位置
while(i <= L.length && !(* compare)(*p++,e)) ++i;
if(i <= L.length) return i;
else return 0;
} //该函数的时间复杂度为O(n)
 
/*销毁线性表的函数*/
Status Clear_Sq(SqList &L){
ElemType elem;
free(L.elem);
L.elem = NULL;
return OK;
}
 
/**打印顺序表函数**/
void Print_Sq(SqList L){
int i;
for(i = 0; i < L.length; i++)
printf("%2c",L.elem[i]);
if(L.length == 0) printf("该集合为空集"); 
printf("\n\t\t\t#\t此集合中的个数 n = %d\n\n",L.length);
}
 
/**求集合的并集的函数**/
void Union_Sq(SqList La,SqList Lb,SqList &Lc){
int i;
ElemType elem;
Lc.length=0;
for(i = 0; i < La.length; i++)
Lc.elem[Lc.length++]=La.elem[i];
for(i = 1; i <= Lb.length; i++){
elem = Lb.elem[i-1];
if(!LocateElem_Sq(La,elem,Equal))
ListInsert_Sq(Lc,Lc.length+1,elem);
   }
}
 
/**求集合的交集的函数**/
void Mix_Sq(SqList La,SqList Lb,SqList &Lc){
int i;
ElemType elem;
Lc.length = 0;
for(i = 1; i <= La.length; i++){
elem = La.elem[i-1];
if(LocateElem_Sq(Lb,elem,Equal))
ListInsert_Sq(Lc,Lc.length+1,elem);
   }
}
 
/**求集合的差集函数**/
void Differ_Sq(SqList La,SqList Lb,SqList &Lc){
int i;
ElemType elem;
Lc.length = 0;
for(i = 1; i <= La.length; i++){
elem = La.elem[i-1];
if(!LocateElem_Sq(Lb,elem,Equal))
ListInsert_Sq(Lc,Lc.length+1,elem);
   }
}
 
/**求集合的补集函数**/
void Comple_Sq(SqList La,SqList Lb,SqList &Lc,SqList &Ld){
int i;
ElemType elem;
Ld.length = 0;
Union_Sq(La,Lb,Lc);
for(i = 1; i <= Lc.length; i++){
elem = Lc.elem[i-1];
if(!LocateElem_Sq(La,elem,Equal))
ListInsert_Sq(Ld,Ld.length+1,elem);
}
}
 
void Index_Sq(){
char s;
int l;
l = 1;
 
InitList_Sq(La);
printf("\t\t\t|****** 请输入你的第一个集合：******|\n");
printf("\t\t\t");
CreateList_Sq(La);
printf("\t\t\t#\t集合A为");
Print_Sq(La); //实现表LA的操作
printf("\t\n\n");
 
InitList_Sq(Lb);
printf("\t\t\t|****** 请输入你的第二个集合：******|\n");
printf("\t\t\t");
CreateList_Sq(Lb);
printf("\t\t\t#\t集合B为");
Print_Sq(Lb); //实现表LB的操作
printf("\t\n\n");
 
InitList_Sq(Lc); //初始化表LC的操作
InitList_Sq(Ld); //初始化表Ld的操作
while(l){
printf("\t\t|******* 您可以选择a、b、c或者d执行以下操作 ******|\n\n");
printf("\t\t|************* a、进行集合的并运算 ***************|\n");
printf("\t\t|************* b、进行集合的交运算 ***************|\n");
printf("\t\t|************* c、进行集合的差运算 ***************|\n");
printf("\t\t|************* d、进行集合的补运算 ***************|\n");
printf("\t\t|************* e、重新建立两个集合 ***************|\n");
printf("\t\t\t");
scanf("%c",&s);
switch(s){
case 'a' :  Union_Sq(La,Lb,Lc);
printf("\t\t\t#\t集合A与集合B的并集为:");
Print_Sq(Lc); //实现表LA与表LB并集的操作
printf("\n");
break;
case 'b' : Mix_Sq(La,Lb,Lc);
printf("\t\t\t#\t集合A与集合B的交集为:");
Print_Sq(Lc); //实现表LA与表LB交集的操作
printf("\n");
break;
case 'c' : Differ_Sq(La,Lb,Lc);
printf("\t\t\t#\t集合A与集合B的差集为:");
Print_Sq(Lc); //实现表LA与表LB差集的操作
printf("\n");
break;
case 'd' : Comple_Sq(La,Lb,Lc,Ld);
printf("\t\t\t#\t集合A的补集为:");
Print_Sq(Ld); //实现表LA的补集操作
printf("\n");
break;
case 'e' : Clear_Sq(La);
Clear_Sq(Lb);
Clear_Sq(Lc);
Clear_Sq(Ld);
 
getchar();
Index_Sq();
 
break;
default  : printf("\t\t\t#\tenter data error!\n");
printf("\n");
}
printf("\t\t|**** 您是否还想继续计算。是请输入1，否请输入0 ****|\n");
printf("\t\t\t");
scanf("%d",&l);
getchar();
}//while语句判断是否继续
printf("\n\t\t|**************** 欢迎使用，谢谢！*****************|\n");
getchar();
}
int main(){
printf("\t\t|************* 欢迎使用集合操作运算器 ************|\n");
Index_Sq();
 
return 0;
} 

   
