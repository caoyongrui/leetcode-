/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬����?[0,1,2,4,5,6,7]?���ܱ�Ϊ?[4,5,6,7,0,1,2]?)��

����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻�?-1?��

����Լ��������в������ظ���Ԫ�ء�

����㷨ʱ�临�Ӷȱ�����?O(log?n) ����

ʾ�� 1:

����: nums = [4,5,6,7,0,1,2], target = 0
���: 4
ʾ��?2:

����: nums = [4,5,6,7,0,1,2], target = 3
���: -1
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