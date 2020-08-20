#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//思路：由黄金连分数可转化为求解斐波那契数，运用大数运算求解小数点后一百位
 
//n表示斐波那契数列第一百项
int n = 100; 
int cmp(string a, string b)
{
	if (a == b) return 0;
	else if (a.length() < b.length()) return -1;
	else if (a.length() > b.length()) return 1;
	else
	{
		if (a > b) return 1;
		if (a < b) return -1;
		return -1;
	}
}
 
//大数相加，较大斐波那契数无法算出，只能通过大数计算
string add(string a, string b)
{
	//去掉开头的0,substr(a,n) 返回第a位开始长度为n的字符串
	//find_first_not_of（"abc"）返回最先匹配到abc任意一个字符的最后位置
	a = a.substr(a.find_first_not_of('0'));
	b = b.substr(a.find_first_not_of('0'));
 
	long long lenA = a.length();
	long long lenB = b.length();
	long long len = max(lenA, lenB) + 10;
	//反转， 便于从最低位逐位求和
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans(len, '0');
	for (int i = 0; i < lenA; i++)
	{
		ans[i] = a[i];
	}
	//通过模拟手工计算来进行大数相加，temp用来存储上下两位相加的结果
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		if (i < lenB)
		{
			temp += ((ans[i] - '0') + (b[i] - '0'));
			ans[i] = temp % 10 + '0';
			temp /= 10;
		}
		else
		{
			temp += (ans[i] - '0');
			ans[i] = temp % 10 + '0';
			temp /= 10;
		}
	}
	//ans存储的结果最后要反转回来去掉开头的0
	reverse(ans.begin(), ans.end());
	return ans.substr(ans.find_first_not_of('0'));
}
 
//大数相减
string substract(string a, string b)
{
	//a必须大于b,实际上在divide（）中，a已经>=b了
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	//将a复制给ans
	string ans = a;
	//依旧是模拟手工减法计算
	for (int i = 0; i < b.length(); i++)
	{
		if (ans[i] >= b[i])
		{
			ans[i] = ans[i] - b[i] + '0';
		}
		//注意：在被减数不够减的情况下，需要向前借位，
		//可能被借位为0也不够借，继续往前寻找不为0的位，通过一个while循环实现
		else
		{
			int k = 1;
			while (ans[i + k] == '0')
			{
				//0被借位变为9
				ans[i + k] = '9';
				k++;
			}
			//最终i+k位不为0可以被借-1，i位+10
			ans[i + k] = ans[i + k] - 1;
			ans[i] = ans[i] + 10 - b[i] + '0';
		}
	}
	reverse(ans.begin(), ans.end());
	return ans.substr(ans.find_first_not_of('0'));
}
 
//大数相除
string divide(string a, string b)
{
	//前提 a < b 实际题目已满足
	//大数除法实际上是模拟除法运算结合大数减法
	string ans = "0.";
	for (int i = 0; i < 101; i++) //保留101项，保证四舍五入
	{
		// (a*10)/b = t 不过其中除法用减法substract代替
		a.append(1,'0');
		int t = 0;
		while (cmp(a, b) >= 0)
		{
			a = substract(a, b);
			t++;
		}
		ans.append(1,t + '0');
	}
	return ans;
}
int main()
{
	//斐波那契数列前两项
	string a = "1";
	string b = "1";
	for (int k = 0; k < 40; k++)
	{
		//求解斐波那契数列100-140各项与前一项的比值（所谓黄金连分数）
		for (int i = 3; i < n+k; i++)
		{
			string temp = b;
			b = add(a, b);
			a = temp;
		}
		
		string ans = divide(a, b);
		cout << 100+k  << "项  " <<ans << endl;
	}
 
	return 0;
}
