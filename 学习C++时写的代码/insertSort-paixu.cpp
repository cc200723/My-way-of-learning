#include<iostream> 
using namespace std;

//������������ 
void insertSort(int *data,int number); 


void insertSort(int *data,int number)
{
	int insData;//������Ԫ�أ���һ�θ�ֵΪ�ڶ���Ԫ�أ����ֵΪδ����Ԫ���еĵ�һ�� 
	for(int i=1;i<number;i++)
	{
		insData=data[i];
		int j=i;//j���������¼insDataԪ��Ӧ�÷����λ���±�
		 
		//whileѭ��ΪinsԪ��Ѱ��λ�� �������±�Ϊj��Ԫ�ؿ�ʼ���� 
		while((j>0)&&(insData<data[j-1]))
		{
			data[j]=data[j-1];
			j--;
		}
		data[j]=insData;//��insData�����Ѿ���������ɸ�Ԫ���� 
		
		//ÿһ�������Ԫ�ص�״̬ 
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
	
