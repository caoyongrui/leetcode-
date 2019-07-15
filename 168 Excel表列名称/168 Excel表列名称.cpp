/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
...
示例 1:

输入: 1
输出: "A"
示例?2:

输入: 28
输出: "AB"
示例?3:

输入: 701
输出: "ZY"
*/

#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int n)
{
	string res;
	while (n)
	{
		if (n % 26 == 0)
		{
			res = 'Z' + res;
			n -= 26;
		}
		else
		{
			char c = 'A' + (n % 26 - 1);
			res = c + res;
		}
		n /= 26;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	string res = convertToTitle(n);
	cout << res << endl;

	system("pause");
	return 0;
}