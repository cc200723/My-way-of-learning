#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//˼·���ɻƽ���������ת��Ϊ���쳲������������ô����������С�����һ��λ
 
//n��ʾ쳲��������е�һ����
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
 
//������ӣ��ϴ�쳲��������޷������ֻ��ͨ����������
string add(string a, string b)
{
	//ȥ����ͷ��0,substr(a,n) ���ص�aλ��ʼ����Ϊn���ַ���
	//find_first_not_of��"abc"����������ƥ�䵽abc����һ���ַ������λ��
	a = a.substr(a.find_first_not_of('0'));
	b = b.substr(a.find_first_not_of('0'));
 
	long long lenA = a.length();
	long long lenB = b.length();
	long long len = max(lenA, lenB) + 10;
	//��ת�� ���ڴ����λ��λ���
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans(len, '0');
	for (int i = 0; i < lenA; i++)
	{
		ans[i] = a[i];
	}
	//ͨ��ģ���ֹ����������д�����ӣ�temp�����洢������λ��ӵĽ��
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
	//ans�洢�Ľ�����Ҫ��ת����ȥ����ͷ��0
	reverse(ans.begin(), ans.end());
	return ans.substr(ans.find_first_not_of('0'));
}
 
//�������
string substract(string a, string b)
{
	//a�������b,ʵ������divide�����У�a�Ѿ�>=b��
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	//��a���Ƹ�ans
	string ans = a;
	//������ģ���ֹ���������
	for (int i = 0; i < b.length(); i++)
	{
		if (ans[i] >= b[i])
		{
			ans[i] = ans[i] - b[i] + '0';
		}
		//ע�⣺�ڱ�����������������£���Ҫ��ǰ��λ��
		//���ܱ���λΪ0Ҳ�����裬������ǰѰ�Ҳ�Ϊ0��λ��ͨ��һ��whileѭ��ʵ��
		else
		{
			int k = 1;
			while (ans[i + k] == '0')
			{
				//0����λ��Ϊ9
				ans[i + k] = '9';
				k++;
			}
			//����i+kλ��Ϊ0���Ա���-1��iλ+10
			ans[i + k] = ans[i + k] - 1;
			ans[i] = ans[i] + 10 - b[i] + '0';
		}
	}
	reverse(ans.begin(), ans.end());
	return ans.substr(ans.find_first_not_of('0'));
}
 
//�������
string divide(string a, string b)
{
	//ǰ�� a < b ʵ����Ŀ������
	//��������ʵ������ģ����������ϴ�������
	string ans = "0.";
	for (int i = 0; i < 101; i++) //����101���֤��������
	{
		// (a*10)/b = t �������г����ü���substract����
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
	//쳲���������ǰ����
	string a = "1";
	string b = "1";
	for (int k = 0; k < 40; k++)
	{
		//���쳲���������100-140������ǰһ��ı�ֵ����ν�ƽ���������
		for (int i = 3; i < n+k; i++)
		{
			string temp = b;
			b = add(a, b);
			a = temp;
		}
		
		string ans = divide(a, b);
		cout << 100+k  << "��  " <<ans << endl;
	}
 
	return 0;
}
