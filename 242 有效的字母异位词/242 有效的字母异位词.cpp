/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

ʾ��?1:

����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:

����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��

����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isAnagram(string s, string t)
{
	int len1 = s.length();
	int len2 = t.length();
	if (len1 != len2)
		return false;
	map<char, int> m1;
	map<char, int> m2;
	for (int i = 0; i < len1; i++)
	{
		if (m1.find(s[i]) == m1.end())
			m1.insert(make_pair(s[i], 1));
		else
			m1[s[i]]++;
	}
	for (int i = 0; i < len2; i++)
	{
		if (m2.find(t[i]) == m2.end())
			m2.insert(make_pair(t[i], 1));
		else
			m2[t[i]]++;
	}
	if (m1 == m2)
		return true;
	return false;
}

int main()
{
	string s = "rat";
	string t = "cat";
	bool res = isAnagram(s, t);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}