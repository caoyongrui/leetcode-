/*
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��

����:

s = "leetcode"
���� 0.

s = "loveleetcode",
���� 2.
?

 ע����������Լٶ����ַ���ֻ����Сд��ĸ��
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int firstUniqChar(string s)
{
	int len = s.length();
	map<char, int> um;
	for (int i = 0; i < len; i++)
	{
		if (um.find(s[i]) == um.end())
			um[s[i]] = 1;
		else
			um[s[i]] += 1;
	}
	for (int i = 0; i < len; i++)
	{
		if (um[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	string s = "loveleetcode";
	int res = firstUniqChar(s);
	cout << res << endl;

	system("pause");
	return 0;
}