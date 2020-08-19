#include <iostream>
using namespace std;

//函数原型 
void outPut(int array[], int number);
void sortBubble(int array[],int number);



//练习，标出一下代码中变量的作用域，生存期 
//修改为既可以升序，也可以降序 
void sortBubble(int array[],int number)   
{
	int temp,i,j;
	int flag=0;
	for(i=0;i<number-1;i++)
	{
		//pos=i;
		for(j=0;j<number-i-1;j++)
		{
			if(array[j]>array[j+1])//升序 
		    {
			  temp=array[j];
		      array[j]=array[j+1];
		      array[j+1]=temp;
		      flag=1;
		    }
		}
		    if(flag==0)//flag为零表示已经没有 交换，那么表明数据已经有序 
		    { 
		       cout<<" no exchange ,then the data is already sequence"<<endl;
		       break;
		   }
	
	//	outPut(array,number);
		
	}
	
}

		

void outPut(int array[], int number)
{
	for(int i=0;i<number;i++)
	{
		cout<<array[i]<<"    ";
	}
	cout<<endl;
}



int main()
{
	//int array_int[5]={3,6,2,9,4};
	int array_int[5]={3,4,5,6,7};
	/*int location=maxInt(array_int,5);
	cout<<array_int[location] <<endl;*/
	sortBubble(array_int,5);
	outPut(array_int,5);
	return 0;
}
	
