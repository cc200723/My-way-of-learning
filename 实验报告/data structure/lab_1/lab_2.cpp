#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LIST_INIT_SIZE 100 //��ʼ��ռ��С
#define LISTINCREMENT 10 //������
typedef int Status; /**Status�Ǻ������ͣ���ֵ�Ǻ������״̬���룬��OK��**/
typedef char ElemType; /*ElemType���͸���ʵ������������������Ϊchar*/
/**˳���Ķ���**/
typedef struct{
ElemType *elem; /**����ռ����ַ**/
int length; /**��ǰ����**/
int listsize; /**��ǰ����Ĵ�����������sizeof(Elemtype)Ϊ��λ��**/
}SqList;
 
SqList La,Lb,Lc,Ld; /**����ȫ�ֱ���**/
 
/**����һ���յ����Ա�L**/
Status InitList_Sq(SqList &L){
L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
if(!L.elem) exit(OVERFLOW); /**�������ʧ��**/
L.length = 0; /**�ձ���Ϊ0**/
L.listsize = LIST_INIT_SIZE; /**��ʼ��������**/
return OK;
} /**�ú�����ʱ�临�Ӷ�ΪO(n)**/
 
/**��˳�����߼�Ϊi��λ�ò�����Ԫ��e�ĺ���**/
Status ListInsert_Sq(SqList &L,int i,ElemType e){
ElemType *newbase,*p,*q;
//i�ĺϷ�ֵΪ(1 <= i <= L.length_Sq(L) + 1)
//�쳣����
if(i < 1 || i > L.length + 1) return ERROR;
if(L.length >= L.listsize){ //��ǰ����ռ����������ӷ���
newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(ElemType));
if(!newbase) exit(OVERFLOW); //�������ʧ��
L.elem = newbase; //�»�ַ
L.listsize += LISTINCREMENT; //���Ӵ�������
}
q = &(L.elem[i - 1]); //qΪ����λ��
for(p = &(L.elem[L.length - 1]); p >= q; --p) 
*(p + 1) = *p; //����λ�ü�֮���Ԫ��������
*q = e; //����e
++L.length; //����1
return OK;
}
 
/**����һ�����Ա�����������,���ݼ��϶��壺�����е�Ԫ�ز�����ȴ���**/
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
/**�ж���Ԫ���Ƿ����,������򷵻�TRUE;���򷵻�FALSE**/
Status Equal(ElemType a,ElemType b){
if(a == b) return TRUE;
else return FALSE;
}
 
/**��˳�����Ա�L�в��ҵ�1����e����compare()��Ԫ��λ�����ҵ����򷵻�����L�е�λ�򣬷��򷵻�0**/
int LocateElem_Sq(SqList L,ElemType e,Status(* compare)(ElemType,ElemType)){
ElemType *p;
int i;
i = 1; //i�ĳ�ֵΪ��1��Ԫ�ص�λ��
p = L.elem; //p�ĳ�ֵΪ��1��Ԫ�صĴ���λ��
while(i <= L.length && !(* compare)(*p++,e)) ++i;
if(i <= L.length) return i;
else return 0;
} //�ú�����ʱ�临�Ӷ�ΪO(n)
 
/*�������Ա�ĺ���*/
Status Clear_Sq(SqList &L){
ElemType elem;
free(L.elem);
L.elem = NULL;
return OK;
}
 
/**��ӡ˳�����**/
void Print_Sq(SqList L){
int i;
for(i = 0; i < L.length; i++)
printf("%2c",L.elem[i]);
if(L.length == 0) printf("�ü���Ϊ�ռ�"); 
printf("\n\t\t\t#\t�˼����еĸ��� n = %d\n\n",L.length);
}
 
/**�󼯺ϵĲ����ĺ���**/
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
 
/**�󼯺ϵĽ����ĺ���**/
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
 
/**�󼯺ϵĲ����**/
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
 
/**�󼯺ϵĲ�������**/
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
printf("\t\t\t|****** ��������ĵ�һ�����ϣ�******|\n");
printf("\t\t\t");
CreateList_Sq(La);
printf("\t\t\t#\t����AΪ");
Print_Sq(La); //ʵ�ֱ�LA�Ĳ���
printf("\t\n\n");
 
InitList_Sq(Lb);
printf("\t\t\t|****** ��������ĵڶ������ϣ�******|\n");
printf("\t\t\t");
CreateList_Sq(Lb);
printf("\t\t\t#\t����BΪ");
Print_Sq(Lb); //ʵ�ֱ�LB�Ĳ���
printf("\t\n\n");
 
InitList_Sq(Lc); //��ʼ����LC�Ĳ���
InitList_Sq(Ld); //��ʼ����Ld�Ĳ���
while(l){
printf("\t\t|******* ������ѡ��a��b��c����dִ�����²��� ******|\n\n");
printf("\t\t|************* a�����м��ϵĲ����� ***************|\n");
printf("\t\t|************* b�����м��ϵĽ����� ***************|\n");
printf("\t\t|************* c�����м��ϵĲ����� ***************|\n");
printf("\t\t|************* d�����м��ϵĲ����� ***************|\n");
printf("\t\t|************* e�����½����������� ***************|\n");
printf("\t\t\t");
scanf("%c",&s);
switch(s){
case 'a' :  Union_Sq(La,Lb,Lc);
printf("\t\t\t#\t����A�뼯��B�Ĳ���Ϊ:");
Print_Sq(Lc); //ʵ�ֱ�LA���LB�����Ĳ���
printf("\n");
break;
case 'b' : Mix_Sq(La,Lb,Lc);
printf("\t\t\t#\t����A�뼯��B�Ľ���Ϊ:");
Print_Sq(Lc); //ʵ�ֱ�LA���LB�����Ĳ���
printf("\n");
break;
case 'c' : Differ_Sq(La,Lb,Lc);
printf("\t\t\t#\t����A�뼯��B�ĲΪ:");
Print_Sq(Lc); //ʵ�ֱ�LA���LB��Ĳ���
printf("\n");
break;
case 'd' : Comple_Sq(La,Lb,Lc,Ld);
printf("\t\t\t#\t����A�Ĳ���Ϊ:");
Print_Sq(Ld); //ʵ�ֱ�LA�Ĳ�������
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
printf("\t\t|**** ���Ƿ���������㡣��������1����������0 ****|\n");
printf("\t\t\t");
scanf("%d",&l);
getchar();
}//while����ж��Ƿ����
printf("\n\t\t|**************** ��ӭʹ�ã�лл��*****************|\n");
getchar();
}
int main(){
printf("\t\t|************* ��ӭʹ�ü��ϲ��������� ************|\n");
Index_Sq();
 
return 0;
} 

   
