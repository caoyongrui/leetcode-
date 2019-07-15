/*
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������
*/

#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
	if (needle.length() == 0)
	{
		return 0;
	}
	int res = -1;
	bool state = false;
	for (int i = 0; i < haystack.length(); i++)
	{
		if (haystack[i] == needle[0])
		{
			int j;
			for (j = 1; j < needle.length(); j++)
			{
				if (i + j >= haystack.length() || haystack[i + j] != needle[j])
				{
					break;
				}
			}
			if (j == needle.length())
			{
				state = true;
			}
		}
		if (state == true)
		{
			res = i;
			break;
		}
	}
	return res;
}

int strStr1(string haystack, string needle)
{
	if (needle.length() == 0)
		return 0;
	if (haystack.length() < needle.length())
		return -1;
	for (int i = 0; i < haystack.length() - needle.length() + 1; i++)
	{
		if (haystack.substr(i, needle.length()) == needle)
			return i;
	}
	return -1;
}

int main()
{
	string haystack = "hello";
	string needle = "ll";
	int res = strStr1(haystack, needle);
	cout << res << endl;

	system("pause");
	return 0;
}