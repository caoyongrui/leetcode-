/*
����һ��Excel����е������ƣ���������Ӧ������š�

���磬

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
ʾ�� 1:

����: "A"
���: 1
ʾ��?2:

����: "AB"
���: 28
ʾ��?3:

����: "ZY"
���: 701
*/

#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string s)
{
	int res = 0;
	int j;
	for (int i = s.length() - 1, j = 0; i >= 0; i--, j++)
	{
		res += (s[i] - 'A' + 1) * pow(26, j);
	}
	return res;
}

int main()
{
	string s = "ZY";
	int res = titleToNumber(s);
	cout << res << endl;

	system("pause");
	return 0;
}