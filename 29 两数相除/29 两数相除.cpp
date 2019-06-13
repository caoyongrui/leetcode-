/*
给定两个整数，被除数?dividend?和除数?divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数?dividend?除以除数?divisor?得到的商。

示例?1:

输入: dividend = 10, divisor = 3
输出: 3
示例?2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为?0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [?231,? 231?? 1]。本题中，如果除法结果溢出，则返回 231?? 1。
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