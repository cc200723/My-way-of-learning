#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
     int x,w;//x��ʾ���۶w��ʾнˮ	
     printf(" ���������۶"); 
     scanf("%d",&x);
     if(x<=3000)
     {  w = 2000 * 1.0;
	    printf("нˮΪ��%d",w);
     }
     else if(3000<=x<=7000)
     {  w = 2000 + x * 0.1;
	     printf("нˮΪ��%d",w);
     }
     else if(7000<=x<=10000)
   	{ w=2000 + x * 0.15;
		 printf("нˮΪ��%d",w);
    }
     	   		
	     
     else
     {  w = 2000 + x * 0.2;
	     printf("нˮΪ��%d",w);
     }
     return 0;
}
 
 
 
 
 
 
 
 
