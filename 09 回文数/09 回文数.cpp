/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
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
	long res = 0; //设置为long类型，输入1234567，反转后变成7654321
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