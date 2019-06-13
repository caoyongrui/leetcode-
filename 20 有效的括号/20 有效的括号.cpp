/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/

#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

bool isValid(string s)
{
	if (s.length() == 0)
	{
		return true;
	}
	stack<char> sta;
	map<char, char> m;
	m.insert(make_pair(')', '('));
	m.insert(make_pair(']', '['));
	m.insert(make_pair('}', '{'));
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			sta.push(s[i]);
		}
		else
		{
			if (sta.empty())
			{
				return false;
			}
			char c = sta.top();
			if (m[s[i]] == c)
			{
				sta.pop();
			}
			else
			{
				return false;
			}
		}
	}
	if (sta.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string s = "";
	bool res = isValid(s);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}