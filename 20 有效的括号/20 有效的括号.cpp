/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:

����: "()"
���: true
ʾ�� 2:

����: "()[]{}"
���: true
ʾ�� 3:

����: "(]"
���: false
ʾ�� 4:

����: "([)]"
���: false
ʾ�� 5:

����: "{[]}"
���: true
*/

#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

bool isValid(string s)
{
	if (s.length() == 0)
	{
		return true;
	}
	stack<char> sta;
	map<char, char> m;
	m.insert(make_pair(')', '('));
	m.insert(make_pair(']', '['));
	m.insert(make_pair('}', '{'));
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			sta.push(s[i]);
		}
		else
		{
			if (sta.empty())
			{
				return false;
			}
			char c = sta.top();
			if (m[s[i]] == c)
			{
				sta.pop();
			}
			else
			{
				return false;
			}
		}
	}
	if (sta.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string s = "";
	bool res = isValid(s);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}