/*
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:

����: "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
ʾ�� 2:

����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
ʾ�� 3:

����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
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
			state = true; //��ԭ��־λ
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
			state = true; //��ԭ��־λ
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
				break; //�Ӵ��������������������Ӵ�Ҳ������
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
