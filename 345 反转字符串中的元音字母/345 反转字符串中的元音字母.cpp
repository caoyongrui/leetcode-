/*
��дһ�����������ַ�����Ϊ���룬��ת���ַ����е�Ԫ����ĸ��

ʾ�� 1:

����: "hello"
���: "holle"
ʾ�� 2:

����: "leetcode"
���: "leotcede"
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

string reverseVowels(string s)
{
	int len = s.length();
	if (!len)
		return{};
	if (len == 1)
		return s;
	string res = s;
	int i = 0;
	int j = len - 1;
	set<char> v = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	while (i < j)
	{
		if (v.find(res[i]) != v.end())
		{
			if (v.find(res[j]) != v.end())
			{
				char c = res[i];
				res[i] = res[j];
				res[j] = c;
				i++;
				j--;
			}
			else
				j--;
		}
		else if (v.find(res[j]) != v.end())
		{
			if (v.find(res[i]) != v.end())
			{
				char c = res[i];
				res[i] = res[j];
				res[j] = c;
				i++;
				j--;
			}
			else
				i++;
		}
		else
		{
			i++;
			j--;
		}
	}
	return res;
}

int main()
{
	string s = "leetcode";
	string res = reverseVowels(s);
	cout << res << endl;

	system("pause");
	return 0;
}