/*
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
ʾ��:

���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
˵��:
��������Ĵ��ǰ��ֵ������еģ��������������ѡ��������˳��
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> letterCombinations(string digits)
{
	if (digits.length() == 0)
	{
		return{};
	}
	map<char, string> m = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
	vector<string> res, temp;
	map<char, string>::iterator c;
	for (int i = 0; i < digits.size(); i++)
	{
		c = m.find(digits[i]);
		if(res.empty())
			for (auto bb : c->second)
			{
				res.push_back(string{ bb });
			}
		else
		{
			for (auto a : res)
			{
				for (auto c : c->second)
				{
					temp.push_back(a + c);
				}
			}
			res = temp;
			temp.clear();
		}
	}
	return res;
}

int main()
{
	string digits = "237";
	vector<string> res;
	res = letterCombinations(digits);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}