#include<iostream>
using namespace std;
int fun(int b[10],int n)
{
	int j,m,temp;
	for(j=0;j<n/2;j++)
	{
		temp=b[j];
		b[j]=b[10-j-1];
		b[10-1-j]=temp;
	}
}
int main()
{
	int i,a[10];
	for(i=0;i<10;i++)
	cin>>a[i];
	fun(a,10);
	for(i=0;i<10;i++)
	cout<<" "<<a[i];
	return 0;
} 



