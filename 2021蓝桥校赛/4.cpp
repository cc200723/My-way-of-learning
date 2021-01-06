/*
边输入边处理，我们容易知道，每一行的最后一个数的下标都是等于
(2^n)-1，比如第二行的最后一个数等于2^2-1=3,第三行的最后一个数等于2^3-1=7,用deep表示当前深度，
从当前这行的第一项加到最后一项然后和最大值max_sum比较。
*/

#include<iostream>
#include<cstdio> 
#include<cstdlib>
#include<cmath>
using namespace std;
int Ai[100005];
int main(){
	int N;
	int deep = 1; //深度 
	int sum = 0; //每行的和 
	long long max_sum = -100000000000; //最大的和 
	int max_deep = 1;
	cin>>N;
	for(int i = 1; i <= N; ++i){
		cin>>Ai[i];
		sum += Ai[i];
		if(i == pow(2, deep) - 1){
			if(max_sum < sum){ //注意不要取等号，因为题目要最小的深度 
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
