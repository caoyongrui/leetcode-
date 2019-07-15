/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间;?4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间;?8,9 可组成一个连续的区间。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
	int len = nums.size();
	vector<string> res;
	if (!len)
		return res;
	if (len == 1)
	{
		res.push_back(to_string(nums[0]));
		return res;
	}
	nums.push_back(INT32_MAX);
	len++;
	for (int i = 0; i < len; i++)
	{
		long long temp = 0;
		for (int k = i; k < len; k++)
		{
			string s;
			long long sub = (long long)nums[k] - (long long)nums[i];
			if (sub != temp)
			{
				if (k - i == 1)
					s = to_string(nums[i]);
				else
					s = to_string(nums[i]) + "->" + to_string(nums[k - 1]);
				res.push_back(s);
				i = k - 1;
				break;
			}
			else
				temp++;
		}
	}
	return res;
}

int main()
{
	vector<int> nums;
	int n;
	while (cin >> n)
	{
		nums.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	vector<string> res = summaryRanges(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}