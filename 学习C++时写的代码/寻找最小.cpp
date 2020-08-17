#include <iostream>
using namespace std;
int getMin(int array[],int number);
int getMin(int array[],int number){
int temp=array[0];
int j=0;
for(int i=1;i<number;i++)
{
	if (temp>=array[i])
	{
		temp=array[i];
		j=i;
	}
}	
  return j;
} 
int main(){
	 
    int array_int[5]={3,4,5,6,7};
	int j=getMin(array_int,5);
	cout<<array_int[j]<<endl;
	return 0;
}	


