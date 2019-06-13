/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return "";
	}
	string res = strs[0];
	for (int i = 1; i < strs.size(); i++)
	{
		for (int j = 0; j < res.length(); j++)
		{
			if (res[j] == strs[i][j])
			{
				continue;
			}
			else
			{
				res.erase(j);
				break;
			}
		}
	}
	return res;
}

int main()
{
	vector<string> v{ "aa","a" };
	string ret = longestCommonPrefix(v);
	cout << ret << endl;

	system("pause");
	return 0;
}