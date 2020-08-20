#include<stdio.h>
#include <string.h>
#include<malloc.h>
#include<ctype.h>
/*1.编码完成下面的处理函数，函数将字符串中的字符'*'移到字符串的前部分，前面的非'*'
字符后移，但不能改变非'*'字符的先后顺序，函数返回串中非'*'字符的数量。(要求尽可能的占用少的时间和辅助空间)。
例如：原始串为au**toc**h**i*ps,处理后为*******autochips,函数返回9.
(1)请用文字或流程图简要描述您的思路；
(2)请用C语言编程实现，注意时间和空间开销。
(1)先定义一个用于数组的值进行交换的函数swap,再定义函数统计字符数量.
*/
/*void swap(char A[],int a,int b)  
{  
    char temp=A[a];  
    A[a]=A[b];  
    A[b]=temp;  
}  
 
int partiStr(char str[])
{
	int len,i,k,sum;
	len=strlen(str);
	k=-1;
	sum=0;
	for(i=0;i<len;i++)
	{
		if(str[i]=='*')
		{
			k++;
			sum++;
			swap(str,k,i);
		}
	}
	return len-sum;
} 
 int main(){
    char a[]={"au**toc**h**i*ps"};
	char b[sizeof(a)];
	int num;
	printf("%s",a);
	num=partiStr(a);
	printf("处理后为：%s 其他字符的个数为：%d\n",a,num);
	return 0;
}*/
 /*2.将字符串中多个连续的空格删除,只保留一个空格."a b    cd     e"->"a b cd e"*/
	/*char* trim(char* a)
{
	int i=-1,j=0;
	for (;a[j]!='\0';j++)
	{
		if (a[j]==a[j+1] && a[j+1]==' ')
		{
			
			while (a[j]==' ')
			{
				++j;
			}
			--j;
		}
		a[++i]=a[j];
	}
	a[++i]='\0';
	return a;
}
int main( void ) 
{
    char a[100]="a b    cd     e";
	printf(a);
	printf(trim(a));
	return 0;
}*/ 
   /*3.将字符串中的空格替换成"%20".例如"a bc d  e"->"a%20bc%20d%20%20e"*/
void fun1(char * ch)
{
	char *p=ch;
	int n=100;
	int i=0;
	int *arr=(int *)malloc(n*sizeof(int));
	for( i=0;i<n;i++)
	{
		arr[i]=0;
	}
	while(*p!='\0')
	{
		if( isalpha(*p) )
		{
			arr[i]=*p;
			i++;
			p++;
		}
		else
		{
			arr[i]='%20';
			i++;
			p++;
		}
			
	for(;arr[i]!=0;i++)
	{
		printf("%d",arr[i]);
	}
	free(arr);
}
int main()
{   
	char ch=getchar();
	fun1((char*) ch);
	return 0;
}




 

