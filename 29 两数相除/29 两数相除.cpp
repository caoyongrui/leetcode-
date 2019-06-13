/*
��������������������?dividend?�ͳ���?divisor�������������Ҫ��ʹ�ó˷��������� mod �������

���ر�����?dividend?���Գ���?divisor?�õ����̡�

ʾ��?1:

����: dividend = 10, divisor = 3
���: 3
ʾ��?2:

����: dividend = 7, divisor = -3
���: -2
˵��:

�������ͳ�����Ϊ 32 λ�з���������
������Ϊ?0��
�������ǵĻ���ֻ�ܴ洢 32 λ�з�������������ֵ��Χ�� [?231,? 231?? 1]�������У�����������������򷵻� 231?? 1��
*/

#include <iostream>
using namespace std;

int divide(int dividend, int divisor)
{
	long long lldividend = dividend, lldivisor = divisor;
	lldividend = abs(lldividend);
	lldivisor = abs(lldivisor);
	long long bit = 1;
	long long res = 0;
	while (lldividend >= lldivisor << 1)
	{
		lldivisor <<= 1;
		bit <<= 1;
	}
	while (bit > 0 && lldividend > 0)
	{
		if (lldividend >= lldivisor)
		{
			lldividend -= lldivisor;
			res += bit;
		}
		lldivisor >>= 1;
		bit >>= 1;
	}
	res = ((dividend > 0) && (divisor < 0)) || ((dividend < 0) && (divisor > 0)) ? -res : res;
	if (res > INT_MAX)
	{
		return INT_MAX;
	}
	else
	{
		return (int)res;
	}
}

int main()
{
	int res = divide(INT_MIN, -1);
	cout << res << endl;

	system("pause");
	return 0;
}