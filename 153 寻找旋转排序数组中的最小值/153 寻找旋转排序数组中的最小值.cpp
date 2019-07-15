/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组?[0,1,2,4,5,6,7] 可能变为?[4,5,6,7,0,1,2]?)。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0
*/

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
	if (nums.size() == 0)
		return {};
	if (nums.size() == 1)
		return nums[0];
	int i = 0;
	int j = nums.size() - 1;
	if (nums[i] < nums[j])
		return nums[0];
	while (i <= j)
	{
		int mid = (i + j) / 2;
		if (nums[mid] > nums[mid + 1])
			return nums[mid + 1];
		if (nums[mid] > nums[0])
			i = mid;
		else
			j = mid;
	}
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
	int res = findMin(nums);
	cout << res << endl;

	system("pause");
	return 0;
}