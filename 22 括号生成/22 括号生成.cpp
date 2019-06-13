/*
给出?n?代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出?n = 3，生成结果为：

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void helper(string cur, vector<string> &res, int n, int left, int right)
{
	//因为right是右括号，数量=n 表明此时已经找到一个结果
	if (right == n)
	{
		res.push_back(cur);
	}
	//可以添加一个左括号
	if (left < n)
	{
		helper(cur + '(', res, n, left + 1, right);
	}
	//添加一个右括号
	if (right < left)
	{
		helper(cur + ')', res, n, left, right + 1);
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> res;
	helper("", res, n, 0, 0);
	return res;
}

int main()
{
	vector<string> res = generateParenthesis(3);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}

	system("pause");
	return 0;
}