/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例?1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例?2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为?0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() <= 1)
		return nums.size();
	int current = 1;
	for (int i = 2; i < nums.size(); i++)
	{
		if (nums[i] != nums[current - 1])
			nums[++current] = nums[i];
	}
	return current + 1;
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
	int len = removeDuplicates(nums);
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}