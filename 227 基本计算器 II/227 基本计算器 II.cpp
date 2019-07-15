/*
ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ��ֵ��

�ַ������ʽ�������Ǹ�������+�� - ��*��/ ����������Ϳո�??�� ���������������������֡�

ʾ��?1:

����: "3+2*2"
���: 7
ʾ�� 2:

����: " 3/2 "
���: 1
ʾ�� 3:

����: " 3+5 / 2 "
���: 5
˵����

����Լ����������ı��ʽ������Ч�ġ�
�벻Ҫʹ�����õĿ⺯�� eval��
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int calculate(string s)
{
	int len = s.length();
	char op = '+';
	long long num = 0;
	int res = 0;
	stack<int> sta;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0')
		{
			num = num * 10 + s[i] - '0';
		}
		if ((s[i] < '0' && s[i] != ' ') || i == len - 1)
		{
			if (op == '+')
				sta.push(num);
			else if (op == '-')
				sta.push(-num);
			else
			{
				int temp = (op == '*') ? (sta.top() * num) : (sta.top() / num);
				sta.pop();
				sta.push(temp);
			}
			op = s[i];
			num = 0;
		}
	}
	while (!sta.empty())
	{
		res += sta.top();
		sta.pop();
	}
	return res;
}

int main()
{
	string s = "2147483647";
	int res = calculate(s);
	cout << res << endl;

	system("pause");
	return 0;
}