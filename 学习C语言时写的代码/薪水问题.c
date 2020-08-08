#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
     int x,w;//x表示销售额，w表示薪水	
     printf(" 请输入销售额；"); 
     scanf("%d",&x);
     if(x<=3000)
     {  w = 2000 * 1.0;
	    printf("薪水为；%d",w);
     }
     else if(3000<=x<=7000)
     {  w = 2000 + x * 0.1;
	     printf("薪水为；%d",w);
     }
     else if(7000<=x<=10000)
   	{ w=2000 + x * 0.15;
		 printf("薪水为；%d",w);
    }
     	   		
	     
     else
     {  w = 2000 + x * 0.2;
	     printf("薪水为；%d",w);
     }
     return 0;
}
 
 
 
 
 
 
 
 
