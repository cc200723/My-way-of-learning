/*
������ߴ�����������֪����ÿһ�е����һ�������±궼�ǵ���
(2^n)-1������ڶ��е����һ��������2^2-1=3,�����е����һ��������2^3-1=7,��deep��ʾ��ǰ��ȣ�
�ӵ�ǰ���еĵ�һ��ӵ����һ��Ȼ������ֵmax_sum�Ƚϡ�
*/

#include<iostream>
#include<cstdio> 
#include<cstdlib>
#include<cmath>
using namespace std;
int Ai[100005];
int main(){
	int N;
	int deep = 1; //��� 
	int sum = 0; //ÿ�еĺ� 
	long long max_sum = -100000000000; //���ĺ� 
	int max_deep = 1;
	cin>>N;
	for(int i = 1; i <= N; ++i){
		cin>>Ai[i];
		sum += Ai[i];
		if(i == pow(2, deep) - 1){
			if(max_sum < sum){ //ע�ⲻҪȡ�Ⱥţ���Ϊ��ĿҪ��С����� 
				max_deep = deep;
				max_sum = sum;
			}
			sum = 0;
			++deep;
		}
	}
	cout<<max_deep<<endl;
	return 0;
}
