#include <iostream>
using namespace std;

//函数原型 

int insertInt(int array[],int number,int data);
void outPut(int array[], int number);


//假定数组中无此数据 
int insertInt(int array[],int number,int data)
{
	int i=0;int j;
	if(data<array[0])
	{
	   for(j=number;j>i;j--)
	      array[j]=array[j-1];
	  array[0]=data;	
	  return 0;
	}
	else if(data>array[number-1])
	{
		array[number]=data;
		return number;
	}
	else 
	{		
	   for(i=0;i<number;i++)
	  {
		  if(data>array[i]&&data<array[i+1])
		  {   
		      cout<<"the insert position is:"<<i+1<<endl;
		      break;
		  }
	  }
	 for(j=number;j>i;j--)
	     array[j]=array[j-1]; 
     array[i+1]=data;
	return i+1;
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
	int array[6]={3,4,9,11,15};
	int location=insertInt(array,5,12);
	outPut(array,6);
	cout<<location <<"   "<<array[location]<<endl;
	return 0;
}
	
