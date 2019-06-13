/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	vector<string> v;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			string str = s.substr(i, j);
			v.push_back(str);
		}
	}
	int len = 0;
	bool state = true;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].length(); j++)
		{
			for (int k = j + 1; k < v[i].length(); k++)
			{
				if (v[i][j] == v[i][k])
				{
					state = false;
					break;
				}
			}
			if (state == false)
			{
				break;
			}
		}
		if (state == true)
		{
			len = len > v[i].length() ? len : v[i].length();
		}
		else
		{
			state = true; //还原标志位
		}
	}
	return len;
}

int lengthOfLongestSubstring1(string s)
{
	vector<string> v;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			string str = s.substr(i, j);
			v.push_back(str);
		}
	}
	int len = 0;
	bool state = true;
	set<char> cSet;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].length(); j++)
		{
			if (cSet.find(v[i][j]) == cSet.end())
			{
				cSet.insert(v[i][j]);
			}
			else
			{
				state = false;
				break;
			}
		}
		if (state == true)
		{
			len = len > v[i].length() ? len : v[i].length();
		}
		else
		{
			state = true; //还原标志位
		}
		cSet.clear();
	}
	return len;
}

int lengthOfLongestSubstring2(string s)
{
	int len = 0;
	bool state = true;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			string str = s.substr(i, j);
			for (int k = 0; k < str.length(); k++)
			{
				if (str.find(str[k], k + 1) != string::npos)
				{
					state = false;
					break;
				}
			}
			if (state)
			{
				len = len > str.length() ? len : str.length();
			}
			else
			{
				state = true;
				break; //子串不满足条件，更长的子串也不符合
			}
		}
	}
	return len;
}

int lengthOfLongestSubstring3(string s)
{
	int len = 0;
	int curLen = 0;
	int pre = 0;
	int last = pre;
	set<char> m;
	while(last < s.length())
	{
		if (m.find(s[last]) == m.end())
		{
			m.insert(s[last]);
			curLen++;
			len = len > curLen ? len : curLen;
			last++;
		}
		else
		{
			while (s[pre] != s[last])
			{
				m.erase(s[pre]);
				pre++;
				curLen--;
			}
			m.erase(s[pre]);
			pre++;
			curLen--;
		}	
	}
	return len;
}

int main()
{
	string s;
	cin >> s;
	int len = lengthOfLongestSubstring3(s);
	cout << len << endl;

	system("pause");
	return 0;
}
