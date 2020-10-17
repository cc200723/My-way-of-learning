#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MaxSize 50
using namespace std;

 
  //����ջ�ṹ��
typedef struct{
char data[MaxSize];
int top;
}SqStack;
 

 //��ʼ��ջ
void InitStack(SqStack *&s){
s=(SqStack *)malloc(sizeof(SqStack));
s->top=-1;
}
 
//�ж�ջ�Ƿ�Ϊ�� 
bool StackEmpty(SqStack *s){
return(s->top==-1);
}
 
 
//��ջ
bool Push(SqStack *&s,char e){
if(s->top==MaxSize-1)
return false;
s->top++;
s->data[s->top]=e;
return true;
}
 
 //��ջ��Ԫ�ظ���
int StackLength(SqStack *s){
return (s->top+1);
}
 
 //��ջ 
bool Pop(SqStack *s){
int i;
i=s->top;
if(s->top==-1)
return false;
else{
for(;s->top!=-1;s->top--)
{
cout << s->data[s->top] << "  " ;
}
s->top=i;
cout << endl;
return true;
}
}
 
 
 // ��ȡջ��Ԫ�أ�ͬʱ�������˳��ջS
bool Get(SqStack *&s){
if(s->top==-1)
return false;
else{
for(;s->top!=-1;s->top--)
{
cout << s->data[s->top] << "  " ;
}
cout << endl;
return true;
}
}
 
 //�ÿ�ջ 
void DestroyStack(SqStack* &s){
free(s);
}
 
int main()
{
SqStack* s;
InitStack(s);
cout << StackEmpty(s) << endl;
Push(s,'a');
Push(s,'b');
Push(s,'c');
Push(s,'d');
Push(s,'e');
cout << StackEmpty(s) << endl;
cout << StackLength(s) << endl;
Pop(s);
Get(s);
cout << StackEmpty(s) << endl;
DestroyStack(s);
}

 
 
 

