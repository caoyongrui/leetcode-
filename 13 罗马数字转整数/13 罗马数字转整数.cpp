/*
�������ְ������������ַ�: I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��

ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
����һ���������֣�����ת��������������ȷ���� 1 �� 3999 �ķ�Χ�ڡ�

ʾ�� 1:

����: "III"
���: 3
ʾ�� 2:

����: "IV"
���: 4
ʾ�� 3:

����: "IX"
���: 9
ʾ�� 4:

����: "LVIII"
���: 58
����: L = 50, V= 5, III = 3.
ʾ�� 5:

����: "MCMXCIV"
���: 1994
����: M = 1000, CM = 900, XC = 90, IV = 4.
*/

/*
1.ʹ��vector������������һ����˳��
2.����ʹ��map����ΪԪ�ز�����Զ�����
3.string����find()��erase()���÷�
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int romanToInt(string s) {
	vector<string> vRoma{"CM", "M", "CD", "D", "XC", "C", "XL", "L", "IX", "X", "IV", "V", "I"};
	vector<int> vNum{900, 1000, 400, 500, 90, 100, 40, 50, 9, 10, 4, 5, 1};
	int res = 0;
	for (int i = 0; i < 13; i++)
	{
		while (s.find(vRoma[i]) != string::npos)
		{
			s.erase(s.find(vRoma[i]), vRoma[i].size());
			res += vNum[i];
		}
	}
	return res;
}

int main()
{
	int res = romanToInt("MCMXCIV");
	cout << res << endl;

	system("pause");
	return 0;
}