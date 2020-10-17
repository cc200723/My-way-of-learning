#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MaxSize 50
using namespace std;

 
  //定义栈结构体
typedef struct{
char data[MaxSize];
int top;
}SqStack;
 

 //初始化栈
void InitStack(SqStack *&s){
s=(SqStack *)malloc(sizeof(SqStack));
s->top=-1;
}
 
//判断栈是否为空 
bool StackEmpty(SqStack *s){
return(s->top==-1);
}
 
 
//入栈
bool Push(SqStack *&s,char e){
if(s->top==MaxSize-1)
return false;
s->top++;
s->data[s->top]=e;
return true;
}
 
 //求栈的元素个数
int StackLength(SqStack *s){
return (s->top+1);
}
 
 //出栈 
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
 
 
 // 获取栈顶元素，同时遍历输出顺序栈S
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
 
 //置空栈 
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

 
 
 

