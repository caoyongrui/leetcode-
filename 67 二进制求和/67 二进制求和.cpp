/*
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ�ǿ��ַ�����ֻ��������?1?��?0��

ʾ��?1:

����: a = "11", b = "1"
���: "100"
ʾ��?2:

����: a = "1010", b = "1011"
���: "10101"
*/

#include <iostream>
#include <string>
using namespace std;

//��ʹa,b������ͬ
string addBinary(string a, string b)
{
	int aLen = a.length();
	int bLen = b.length();
	while (aLen < bLen)
	{
		a = '0' + a;
		aLen++;
	}
	while (bLen < aLen)
	{
		b = '0' + b;
		bLen++;
	}
	for (int i = aLen - 1; i > 0; i--)
	{
		a[i] = a[i] - '0' + b[i];
		if (a[i] >= '2')
		{
			a[i] = (a[i] - '0') % 2 + '0';
			a[i - 1] = a[i - 1] + 1;
		}
	}
	a[0] = a[0] - '0' + b[0];
	if (a[0] >= '2')
	{
		a[0] = (a[0] - '0') % 2 + '0';
		a = '1' + a;
	}
	return a;
}

int main()
{
	string a = "1010";
	string b = "1011";
	string res = addBinary(a, b);
	cout << res << endl;

	system("pause");
	return 0;
}