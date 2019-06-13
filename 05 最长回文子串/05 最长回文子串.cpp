/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�
ʾ�� 2��

����: "cbbd"
���: "bb"
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string s)
{
	int i = 0;
	int j = s.length() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

string longestPalindrome(string s)
{
	string res = "";
	string str;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			str = s.substr(i, j);
			if (isPalindrome(str))
			{
				if (str.length() > res.length())
				{
					res = str;
				}
			}
		}
	}
	return res;
}

//��̬�滮
string longestPalindrome1(string s)
{
	if (s.length() == 0 || s.length() == 1)
	{
		return s;
	}
	int len = s.length();
	int start = 0;
	int max = 1;
	vector<vector<int>> v(len, vector<int>(len));
	for (int i = 0; i < len; i++)
	{
		v[i][i] = 1;
		if (i < (len - 1) && s[i] == s[i + 1])
		{
			v[i][i + 1] = 1;
			start = i;
			max = 2;
		}
	}
	for (int i = 3; i <= len; i++)
	{
		for (int j = 0; j + i - 1 < len; j++)
		{
			int end = j + i - 1;
			if (s[j] == s[end] && v[j + 1][end - 1] == 1)
			{
				v[j][end] = 1;
				start = j;
				max = i;
			}
		}
	}
	return s.substr(start, max);
}

int main()
{
	string s = "ccc";
	string res = longestPalindrome1(s);
	cout << res << endl;

	system("pause");
	return 0;
}