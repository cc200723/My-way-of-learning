#include <stdio.h>
int main() 
 {
 
int a,b,c,d; 
printf("输入一个三位数a");
scanf("%d",&a);
b=a/100;
c=a%100/10;
d=a%10;	
a=d*100+c*10+b;
printf("a的倒序数字为%d",a);
}


