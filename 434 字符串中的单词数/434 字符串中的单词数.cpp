/*
ͳ���ַ����еĵ��ʸ���������ĵ���ָ���������Ĳ��ǿո���ַ���

��ע�⣬����Լٶ��ַ����ﲻ�����κβ��ɴ�ӡ���ַ���

ʾ��:

����: "Hello, my name is John"
���: 5
*/

#include <iostream>
#include <string>
using namespace std;

int countSegments(string s)
{
	int res = 0;
	int j = 0;
	while (j < s.length() && s[j] == ' ')
		j++;
	s.erase(0, j);
	int len = s.length();
	if (!len)
		return res;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
			continue;
		else
		{
			res++;
			while (i < len && s[i] == ' ')
				i++;
		}
	}
	if (s[len - 1] != ' ')
		return res + 1;
	else
		return res;
}

int main()
{
	string s = "";
	int res = countSegments(s);
	cout << res << endl;

	system("pause");

}