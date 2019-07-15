/*
����һ������������������ Excel �������Ӧ�������ơ�

���磬

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
...
ʾ�� 1:

����: 1
���: "A"
ʾ��?2:

����: 28
���: "AB"
ʾ��?3:

����: 701
���: "ZY"
*/

#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int n)
{
	string res;
	while (n)
	{
		if (n % 26 == 0)
		{
			res = 'Z' + res;
			n -= 26;
		}
		else
		{
			char c = 'A' + (n % 26 - 1);
			res = c + res;
		}
		n /= 26;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	string res = convertToTitle(n);
	cout << res << endl;

	system("pause");
	return 0;
}