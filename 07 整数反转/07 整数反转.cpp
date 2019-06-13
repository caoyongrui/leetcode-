/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [?231,  231 ? 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
/*
1.反转后类型使用long，因为测试用例有的很大
2.pow()函数使用
*/

#include <iostream>
using namespace std;
#include <cmath>

int reverse(int x)
{
	long long res = 0;
	while (x != 0)
	{
		int a = x % 10;
		x /= 10;
		res = res * 10 + a;
		if (res < INT_MIN || res > INT_MAX)
		{
			return 0;
		}
	}
	return (int)res;
}

int main()
{
	int res = reverse(INT_MIN);
	cout << res << endl;

	system("pause");
	return 0;
}