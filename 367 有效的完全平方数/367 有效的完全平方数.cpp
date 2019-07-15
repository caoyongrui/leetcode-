/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如? sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False
*/

#include <iostream>
using namespace std;

bool isPerfectSquare(int num)
{
	int start = 0;
	int end = num;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (pow(mid, 2) == num)
			return true;
		else if (pow(mid, 2) < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
}

int main()
{
	int num;
	cin >> num;
	bool res = isPerfectSquare(num);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}