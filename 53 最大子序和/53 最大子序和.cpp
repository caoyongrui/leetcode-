/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	int temp = 0;
	int ret = INT_MIN;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i; j < nums.size(); j++)
		{
			temp += nums[j];
			ret = ret > temp ? ret : temp;
		}
		temp = 0;
	}
	return ret;
}

//动态规划
int maxSubArray1(vector<int>& nums)
{
	if (nums.size() == 0) return NULL;
	int res = INT_MIN;
	int sum = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum = max(nums[i], sum + nums[i]);
		res = max(sum, res);
	}
	return res;
}

int main()
{
	vector<int> v;
	v.push_back(-2);
	v.push_back(1);
	v.push_back(-3);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-5);
	v.push_back(4);
	int ret = maxSubArray1(v);
	cout << ret << endl;

	system("pause");
	return 0;
}