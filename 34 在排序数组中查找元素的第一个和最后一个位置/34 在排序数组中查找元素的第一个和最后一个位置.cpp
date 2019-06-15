/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是?O(log n) 级别。

如果数组中不存在目标值，返回?[-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例?2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
	int start = 0;
	int end = nums.size() - 1;
	vector<int> res;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (target == nums[mid])
		{
			while (mid >= start && nums[mid] == target)
			{
				mid--;
			}
			res.push_back(mid + 1);
			mid = (start + end) / 2;
			while (mid <= end && nums[mid] == target)
			{
				mid++;
			}
			res.push_back(mid - 1);
			return res;
		}
		else if (target > nums[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return{ -1, -1};
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
	int target;
	cin >> target;
	vector<int> res = searchRange(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}