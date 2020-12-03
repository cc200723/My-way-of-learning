/*三重循环遍历判断
本题只需要用一个三重循环来枚举出所有可能的数，然后来判断这三个数是否符合题目要求即可。
可以写一个专门检测是否包含2或者4的函数，这样代码简洁一些。并且要加入一些判断条件来减小循环次数，
否则运行时间太久了。
最后需要特别注意的是：最后结果要除以6，因为3个数的全排列为6！！！！！不是除以3！
*/


/*
#include <stdio.h>
int check(int n)//判断是否包含2或者4 
{
	int i;
	while(n)
	{
		i=n%10;
		if(i==2 || i==4) 
			return 0;
		n/=10;
	}
	return 1;
}
int main ()
{
	int i,j,k;
	int sum = 0;
	int num = 0;
	for(i=1;i<2019;i++)
	{
		for(j=1;j<2019;j++)
		{
			for(k=1;k<2019;k++) //三重循环来遍历
			{
				if(i==j || i==k || j==k) //如果有相等的直接结束本次循环 
					continue;
				sum = i+j+k;
				if(sum>2019) //如果大于2019了，跳出这个循环，因为接下来的数都会大于2019，可以减小循环次数 
					break;
				if(check(i)==1 && check(j)==1 && check(k)==1 && sum == 2019) //判断 
					num++;
				sum=0; //sum复位0 
			}
		} 
	}
	printf("%d",num/6);//最后结果要除以6，因为3个数的全排列为6，这点要特别注意！！ 
	return 0;
 } 
*/

#include <stdio.h>

int judge(int n) {
	int flag = 1;
//	if(n%10==2 || n%10==4 ||(n/10)%10==2 || (n/10)%10==4 ||(n/100)%10==2 || (n/100)%10==4 || (n/1000)%10==2 || (n/1000)%10==4)
//		flag=0;
	//第二种判断方法,推荐！
	while(n>0) {
		int k=n%10;
		if(k==2 || k==4) {
			flag = 0;
		}
		n/=10;
	}
	return flag;
}

int main () {
	int i,j,k;
	int num = 0;
	for(i= 1; i<=2019; i++) {
		for(j=i+1; j<=2019; j++) {
			for(k=j+1; k<=2019; k++) {
				if(i+j+k==2019) {


					if(judge(i)==1 && judge(j)==1 && judge(k)==1) {
						num++;

					}
				}
			}
		}
	}

	printf("%d",num);
	return 0;
}












