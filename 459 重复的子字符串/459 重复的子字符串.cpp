/*
����һ���ǿյ��ַ������ж����Ƿ����������һ���Ӵ��ظ���ι��ɡ��������ַ���ֻ����СдӢ����ĸ�����ҳ��Ȳ�����10000��

ʾ�� 1:

����: "abab"

���: True

����: �������ַ��� "ab" �ظ����ι��ɡ�
ʾ�� 2:

����: "aba"

���: False
ʾ�� 3:

����: "abcabcabcabc"

���: True

����: �������ַ��� "abc" �ظ��Ĵι��ɡ� (�������ַ��� "abcabc" �ظ����ι��ɡ�)
*/

#include <iostream>
#include <string>
using namespace std;

//�������ж�
bool repeatedSubstringPattern(string s)
{
	int len = s.length();
	for (int i = 1; i <= len / 2; i++)
	{
		if (len % i)
			continue;
		int j = 0;
		for (j = 0; j < len && s[j % i] == s[j]; j++);
		if (j == len)
			return true;
	}
	return false;
}

int main()
{
	string s = "abab";
	bool res = repeatedSubstringPattern(s);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}