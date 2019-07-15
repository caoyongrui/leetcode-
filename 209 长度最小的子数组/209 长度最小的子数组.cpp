/*
给定一个含有?n?个正整数的数组和一个正整数?s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例:?

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组?[4,3]?是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试?O(n log n) 时间复杂度的解法。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
	int minLen = INT32_MAX;
	int len = nums.size();
	int sum;
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += nums[k];
			}
			if (sum >= s)
				minLen = min(minLen, j - i + 1);
		}
	}
	return minLen == INT32_MAX ? 0 : minLen;
}

//滑动窗口解法
int minSubArrayLen1(int s, vector<int>& nums)
{
	int len = nums.size();
	int start = 0;
	int end = 0;
	int minLen = INT32_MAX;
	int sum = 0;
	while (end < len)
	{
		if (sum + nums[end] < s)
		{
			sum += nums[end++];
		}
		else
		{
			minLen = min((end - start + 1), minLen);
			sum -= nums[start++];
		}
	}
	return minLen == INT32_MAX ? 0 : minLen;
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
	cin >> n;
	int res = minSubArrayLen1(n, nums);
	cout << res << endl;

	system("pause");
	return 0;
}