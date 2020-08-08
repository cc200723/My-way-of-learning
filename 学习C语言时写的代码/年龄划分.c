#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
     int old;
	 printf("请输入年龄:"); 
     scanf("%d",&old);
    if(old<=18)
    {
    	printf("少年",old); 
	}
    else if(old<=28)
    {
    	printf("青年",old);
	}
    else if(old<=55) 
    {
    	printf("中年",old);
	}
    else 
    {
    	printf("老年",old);
	}
  return 0; 
	
}
