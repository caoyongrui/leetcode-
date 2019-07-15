/*
����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����

ʾ��:

����: ["eat", "tea", "tan", "ate", "nat", "bat"],
���:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
˵����

���������ΪСд��ĸ��
�����Ǵ������˳��
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