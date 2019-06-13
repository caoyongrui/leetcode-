/*
给定一个仅包含大小写字母和空格?' '?的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0?。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5
*/

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
	if (s.empty())
	{
		return 0;
	}
	int pos = s.rfind(' ');
	while (pos == s.length() - 1)
	{
		if (s.empty())
		{
			return 0;
		}
		s.erase(pos);
		pos = s.rfind(' ');
	}
	return s.length() - pos - 1;
}

int main()
{
	string s = " ";
	int res = lengthOfLastWord(s);
	cout << res << endl;

	system("pause");
	return 0;
}