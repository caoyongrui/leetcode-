/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格??。 整数除法仅保留整数部分。

示例?1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。
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