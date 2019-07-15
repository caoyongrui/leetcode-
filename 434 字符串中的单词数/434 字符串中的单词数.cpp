/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
*/

#include <iostream>
#include <string>
using namespace std;

int countSegments(string s)
{
	int res = 0;
	int j = 0;
	while (j < s.length() && s[j] == ' ')
		j++;
	s.erase(0, j);
	int len = s.length();
	if (!len)
		return res;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
			continue;
		else
		{
			res++;
			while (i < len && s[i] == ' ')
				i++;
		}
	}
	if (s[len - 1] != ' ')
		return res + 1;
	else
		return res;
}

int main()
{
	string s = "";
	int res = countSegments(s);
	cout << res << endl;

	system("pause");

}