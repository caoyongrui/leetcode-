/*
给定一个整数，写一个函数来判断它是否是 3?的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/

#include <iostream>
using namespace std;

bool isPowerOfThree(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (pow(3, i) == n)
			return true;
		else if (pow(3, i) > n)
			return false;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	bool res = isPowerOfThree(n);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}