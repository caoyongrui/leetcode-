/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
?

 注意事项：您可以假定该字符串只包含小写字母。
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int firstUniqChar(string s)
{
	int len = s.length();
	map<char, int> um;
	for (int i = 0; i < len; i++)
	{
		if (um.find(s[i]) == um.end())
			um[s[i]] = 1;
		else
			um[s[i]] += 1;
	}
	for (int i = 0; i < len; i++)
	{
		if (um[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	string s = "loveleetcode";
	int res = firstUniqChar(s);
	cout << res << endl;

	system("pause");
	return 0;
}