/*
给定一种规律 pattern?和一个字符串?str?，判断 str 是否遵循相同的规律。

这里的?遵循?指完全匹配，例如，?pattern?里的每个字母和字符串?str?中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例?4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设?pattern?只包含小写字母，?str?包含了由单个空格分隔的小写字母。
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> split(string str)
{
	int len = str.length();
	int start = 0;
	int count = 0;
	vector<string> res;
	for (int i = 0; i < len;)
	{
		while (i < len && str[i] != ' ')
		{
			i++;
			count++;
		}
		res.push_back(str.substr(start, count));
		start = ++i;
		count = 0;
	}
	return res;
}

bool wordPattern(string pattern, string str)
{
	vector<string> strs = split(str);
	int len1 = pattern.length();
	int len2 = strs.size();
	if (len1 != len2)
		return false;
	if (len1 == 0)
		return true;
	map<char, string> m;
	m.insert(make_pair(pattern[0], strs[0]));
	for (int i = 1; i < len1; i++)
	{
		if (m.find(pattern[i]) == m.end())
		{
			for (auto j : m)
			{
				if (j.second == strs[i])
					return false;
			}
			m.insert(make_pair(pattern[i], strs[i]));
		}
		else
		{
			if (m[pattern[i]] != strs[i])
				return false;
		}
	}
	return true;
}

int main()
{
	string pattern = "abba";
	string str = "dog dog dog dog";
	bool res = wordPattern(pattern, str);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}