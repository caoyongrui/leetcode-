/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/

#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
	if (needle.length() == 0)
	{
		return 0;
	}
	int res = -1;
	bool state = false;
	for (int i = 0; i < haystack.length(); i++)
	{
		if (haystack[i] == needle[0])
		{
			int j;
			for (j = 1; j < needle.length(); j++)
			{
				if (i + j >= haystack.length() || haystack[i + j] != needle[j])
				{
					break;
				}
			}
			if (j == needle.length())
			{
				state = true;
			}
		}
		if (state == true)
		{
			res = i;
			break;
		}
	}
	return res;
}

int strStr1(string haystack, string needle)
{
	if (needle.length() == 0)
		return 0;
	if (haystack.length() < needle.length())
		return -1;
	for (int i = 0; i < haystack.length() - needle.length() + 1; i++)
	{
		if (haystack.substr(i, needle.length()) == needle)
			return i;
	}
	return -1;
}

int main()
{
	string haystack = "hello";
	string needle = "ll";
	int res = strStr1(haystack, needle);
	cout << res << endl;

	system("pause");
	return 0;
}