/*
����һ�ֹ��� pattern?��һ���ַ���?str?���ж� str �Ƿ���ѭ��ͬ�Ĺ��ɡ�

�����?��ѭ?ָ��ȫƥ�䣬���磬?pattern?���ÿ����ĸ���ַ���?str?�е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�

ʾ��1:

����: pattern = "abba", str = "dog cat cat dog"
���: true
ʾ�� 2:

����:pattern = "abba", str = "dog cat cat fish"
���: false
ʾ�� 3:

����: pattern = "aaaa", str = "dog cat cat dog"
���: false
ʾ��?4:

����: pattern = "abba", str = "dog dog dog dog"
���: false
˵��:
����Լ���?pattern?ֻ����Сд��ĸ��?str?�������ɵ����ո�ָ���Сд��ĸ��
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