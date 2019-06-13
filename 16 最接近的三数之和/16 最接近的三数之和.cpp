/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() < 3)
	{
		return 0;
	}
	int closest = INT_MAX;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++)
	{
		int num1 = nums[i];
		if (num1 > target && abs(target - num1 - nums[i + 1] - nums[i + 2]) > abs(closest - target))
		{
			break;
		}
		for (int j = i + 1; j < nums.size() - 1; j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				closest = abs(target - num1 - nums[j] - nums[k]) < abs(target - closest) ? (num1 + nums[j] + nums[k]) : closest;
			}
		}
	}
	return closest;
}

//双指针碰撞法
int threeSumClosest1(vector<int>& nums, int target)
{
	if (nums.size() < 3)
	{
		return 0;
	}
	sort(nums.begin(), nums.end());
	int closest = INT_MAX;
	for (int i = 0; i < nums.size(); i++)
	{
		int num1 = nums[i];
		int j = i + 1;
		int k = nums.size() - 1;
		while (j < k)
		{
			if (num1 + nums[j] + nums[k] == target)
			{
				return target;
			}
			else if (num1 + nums[j] + nums[k] < target)
			{
				closest = abs(target - num1 - nums[j] - nums[k]) < abs(target - closest) ? (num1 + nums[j] + nums[k]) : closest;
				j++;
			}
			else
			{
				closest = abs(target - num1 - nums[j] - nums[k]) < abs(target - closest) ? (num1 + nums[j] + nums[k]) : closest;
				k--;
			}
		}
	}
	return closest;
}

int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-4);
	int res = threeSumClosest1(nums, 1);
	cout << res << endl;

	system("pause");
	return 0;
}