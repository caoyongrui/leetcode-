/*
给定一个字符串，逐个翻转字符串中的每个单词。

?

示例 1：

输入: "the sky is blue"
输出:?"blue is sky the"
示例 2：

输入: " ?hello world! ?"
输出:?"world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good ? example"
输出:?"example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 ?

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
  ?

进阶：

请选用 C 语言的用户尝试使用?O(1) 额外空间复杂度的原地解法。
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseWords(string s)
{
	s.erase(0, s.find_first_not_of(' '));
	s.erase(s.find_last_not_of(' ') + 1);
	string res;
	int i = 0;
	string temp = "";
	stack<string> sta;
	while (i <= s.length())
	{
		if (s[i] == ' ' || s[i] == '\0')
		{
			if (temp.length())
			{
				sta.push(temp);
				temp = "";
			}
		}
		else
			temp += s[i];
		i++;
	}
	int size = sta.size();
	for (int i = 0; i < size; i++)
	{
		if (sta.size() == 1)
			res += sta.top();
		else
		{
			res += sta.top() + ' ';
			sta.pop();
		}
	}
	return res;
}

int main()
{
	string s = "  hello world!  ";
	string res = reverseWords(s);
	cout << res << endl;

	system("pause");
	return 0;
}