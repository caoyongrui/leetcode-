/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
示例 1:

输入: "A"
输出: 1
示例?2:

输入: "AB"
输出: 28
示例?3:

输入: "ZY"
输出: 701
*/

#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string s)
{
	int res = 0;
	int j;
	for (int i = s.length() - 1, j = 0; i >= 0; i--, j++)
	{
		res += (s[i] - 'A' + 1) * pow(26, j);
	}
	return res;
}

int main()
{
	string s = "ZY";
	int res = titleToNumber(s);
	cout << res << endl;

	system("pause");
	return 0;
}