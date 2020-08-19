#include <iostream>
using namespace std;

//函数原型 
void outPut(int array[], int number);
int seek(int array[],int number,int seekData);



int seek(int array[],int number,int seekData)   //返回找到的元素的下标，否则返回-1 
{
	int high,low ,middle;
	low=0;
	high=number-1;
	middle=number/2;
	
	while(low<=high)
	{		
			middle=(low+high)/2;
			if(seekData==array[middle]) 
		    {
		    	return middle;
		    }
		    else if (seekData>array[middle]) 
		    {
		    	low=middle+1;		    	
		    }		    
			else if (seekData<array[middle]) 
		    {
		    	high=middle-1;
		    }
		    
	}	
	return -1;
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
	//sortBubble(array_int,5);
	cout<<seek(array_int,5,3) ;
	//outPut(array_int,5);
	return 0;
}
	
