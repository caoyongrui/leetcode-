/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例?1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例?2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	vector<int> res = digits;
	int temp = 0;
	int num;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (i == digits.size() - 1)
		{
			num = digits[i] + 1;	
		}
		else
		{
			num = digits[i] + temp;
		}
		temp = num / 10;
		res[i] = num % 10;
	}
	if (temp)
	{
		/*res.clear();
		res.push_back(1);
		for (int i = 0; i < digits.size(); i++)
		{
			res.push_back(0);
		}*/
		res.insert(res.begin(), 1);
	}
	return res;
}

int main()
{
	vector<int> digits;
	int n;
	while (cin >> n)
	{
		digits.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	vector<int> res = plusOne(digits);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}