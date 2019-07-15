/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例?1:

输入: [1,2,0]
输出: 3
示例?2:

输入: [3,4,-1,1]
输出: 2
示例?3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int i = 0;
	for (; i < nums.size(); i++)
	{
		if (nums[i] == 1)
			break;
	}
	if (i == nums.size())
		return 1;
	i++;
	int num = 1;
	for (; i < nums.size(); i++)
	{
		if (nums[i] == num)
			continue;
		num++;
		if (nums[i] != num)
			return num;
	}
	return num + 1;
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
	int res = firstMissingPositive(nums);
	cout << res << endl;

	system("pause");
	return 0;
}