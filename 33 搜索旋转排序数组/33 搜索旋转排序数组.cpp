/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组?[0,1,2,4,5,6,7]?可能变为?[4,5,6,7,0,1,2]?)。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回?-1?。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是?O(log?n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例?2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

#include <iostream>
#include <vector>
using namespace std;

int find_rotate_index(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	if (nums[left] < nums[right])
	{
		return 0;
	}
	while (left <= right)
	{
		int pivot = (left + right) / 2;
		if (nums[pivot] > nums[pivot + 1])
			return pivot + 1;
		else
		{
			if (nums[pivot] > nums[left])
				left = pivot;
			else
				right = pivot;
		}
	}
	return 0;
}

int search(int left, int right, vector<int>& nums, int target)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		else if (target > nums[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int search(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;
	if (nums.size() == 1)
		return nums[0] == target ? 0 : -1;
	int rotate_index = find_rotate_index(nums);
	if (target == nums[rotate_index])
		return rotate_index;
	if (rotate_index == 0)
		return search(0, nums.size() - 1, nums, target);
	if (target < nums[0])
		return search(rotate_index, nums.size() - 1, nums, target);
	return search(0, rotate_index - 1, nums, target);
}

int main()
{
	int n;
	vector<int> nums;
	while (cin >> n)
	{
		nums.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int target;
	cin >> target;
	int res = search(nums, target);
	cout << res << endl;

	system("pause");
	return 0;
}