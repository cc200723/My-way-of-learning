#include<stdio.h>
#include <string.h>
#include<malloc.h>
#include<ctype.h>
/*1.�����������Ĵ��������������ַ����е��ַ�'*'�Ƶ��ַ�����ǰ���֣�ǰ��ķ�'*'
�ַ����ƣ������ܸı��'*'�ַ����Ⱥ�˳�򣬺������ش��з�'*'�ַ���������(Ҫ�󾡿��ܵ�ռ���ٵ�ʱ��͸����ռ�)��
���磺ԭʼ��Ϊau**toc**h**i*ps,�����Ϊ*******autochips,��������9.
(1)�������ֻ�����ͼ��Ҫ��������˼·��
(2)����C���Ա��ʵ�֣�ע��ʱ��Ϳռ俪����
(1)�ȶ���һ�����������ֵ���н����ĺ���swap,�ٶ��庯��ͳ���ַ�����.
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
	printf("�����Ϊ��%s �����ַ��ĸ���Ϊ��%d\n",a,num);
	return 0;
}*/
 /*2.���ַ����ж�������Ŀո�ɾ��,ֻ����һ���ո�."a b    cd     e"->"a b cd e"*/
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
   /*3.���ַ����еĿո��滻��"%20".����"a bc d  e"->"a%20bc%20d%20%20e"*/
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




 

