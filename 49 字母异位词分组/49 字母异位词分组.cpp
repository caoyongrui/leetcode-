/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	int len = strs.size();
	vector<vector<string>> res;
	map<string, vector<string>> m;
	for (int i = 0; i < len; i++)
	{
		string s = strs[i];
		sort(s.begin(), s.end());
		m[s].push_back(strs[i]);
	}
	for (auto i:m)
	{
		res.push_back(i.second);
	}
	return res;
}

int main()
{
	vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> res = groupAnagrams(strs);
	cout << '[' << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << '[';
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;

	system("pause");
	return 0;
}