/*
��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�

L   C   I   R
E T O E S I I G
E   D   H   N
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
ʾ�� 1:

����: s = "LEETCODEISHIRING", numRows = 3
���: "LCIRETOESIIGEDHN"
ʾ�� 2:

����: s = "LEETCODEISHIRING", numRows = 4
���: "LDREOEIIECIHNTSG"
����:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/

#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows)
{
	if (numRows == 1)
	{
		return s;
	}
	int len = s.length();
	int cycleLen = 2 * numRows - 2;
	string ret;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j + i < len; j += cycleLen)
		{
			ret += s[j + i];
			if (i != 0 && i != numRows - 1 && j + cycleLen - i < len)
			{
				ret += s[j + cycleLen - i];
			}
		}
	}
	return ret;
}

int main()
{
	string s = "LEETCODEISHIRING";
	string ret = convert(s, 3);
	cout << ret << endl;

	system("pause");
	return 0;
}