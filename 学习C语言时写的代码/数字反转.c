#include <stdio.h>
int main() 
 {
 
int a,b,c,d; 
printf("����һ����λ��a");
scanf("%d",&a);
b=a/100;
c=a%100/10;
d=a%10;	
a=d*100+c*10+b;
printf("a�ĵ�������Ϊ%d",a);
}


