#include<iostream> 
using namespace std;

//插入排序，升序 
void insertSort(int *data,int number); 


void insertSort(int *data,int number)
{
	int insData;//待插入元素，第一次赋值为第二个元素，其后赋值为未就绪元素中的第一个 
	for(int i=1;i<number;i++)
	{
		insData=data[i];
		int j=i;//j变量负责记录insData元素应该放入的位置下标
		 
		//while循环为ins元素寻找位置 ，即从下标为j的元素开始右移 
		while((j>0)&&(insData<data[j-1]))
		{
			data[j]=data[j-1];
			j--;
		}
		data[j]=insData;//将insData放入已经有序的若干个元素中 
		
		//每一轮排序后元素的状态 
	    for(int i=0;i<5;i++)
	       cout<<data[i]<<"   ";
	    cout<<endl;
	}
}

int main()
{
	int data[5]={9,7,1,5,3};
	cout<<"the original data:"<<endl;
	
	for(int i=0;i<5;i++)
	   cout<<data[i]<<"   ";
	cout<<endl;
	cout<<endl;
	cout<<endl;
	insertSort(data,5);
	/*for(int i=0;i<5;i++)
	   cout<<data[i]<<"   ";
	cout<<endl;*/
	
	return 0;
}
	
