/*
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

ʾ�� 1:

����: 121
���: true
ʾ�� 2:

����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
ʾ�� 3:

����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������
*/
#include <iostream>
using namespace std;

bool isPalindrome(int x) {
	if (x == 0)
	{
		return true;
	}
	if (x < 0 || x % 10 == 0)
	{
		return false;
	}
	long res = 0; //����Ϊlong���ͣ�����1234567����ת����7654321
	int temp;
	int xCopy = x;
	while (x != 0)
	{
		temp = x % 10;
		x /= 10;
		res = res * 10 + temp;
	}
	if (res == xCopy)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	bool res = isPalindrome(9);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}