/*
实现?int sqrt(int x)?函数。

计算并返回?x?的平方根，其中?x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
由于返回类型是整数，小数部分将被舍去
*/

#include <iostream>
using namespace std;

//二分查找
int mySqrt(int x)
{
	int i = 0;
	int j = x / 2 + 1; //任何非负数的平方根不会大于x / 2 + 1
	while (i <= j)
	{
		int mid = (i + j) / 2;
		if (x == mid * mid)
		{
			return mid;
		}
		else if (x > mid * mid)
		{
			i = mid + 1;
		}
		else
		{
			j = mid - 1;
		}
	}
	return j;
}

//牛顿法
int mySqrt1(int x)
{
	if (x == 0)
	{
		return 0;
	}
	double temp = 0;
	double res = 1;
	while (temp != res)
	{
		temp = res;
		res = (res + x / res) / 2;
	}
	return (int)res;
}

int main()
{
	int res = mySqrt(0);
	cout << res << endl;

	system("pause");
	return 0;
}