/*
����һ����������Сд��ĸ�Ϳո�?' '?���ַ��������������һ�����ʵĳ��ȡ�

������������һ�����ʣ��뷵�� 0?��

˵����һ��������ָ����ĸ��ɣ����������κοո���ַ�����

ʾ��:

����: "Hello World"
���: 5
*/

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
	if (s.empty())
	{
		return 0;
	}
	int pos = s.rfind(' ');
	while (pos == s.length() - 1)
	{
		if (s.empty())
		{
			return 0;
		}
		s.erase(pos);
		pos = s.rfind(' ');
	}
	return s.length() - pos - 1;
}

int main()
{
	string s = " ";
	int res = lengthOfLastWord(s);
	cout << res << endl;

	system("pause");
	return 0;
}