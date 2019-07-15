/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于?? n/2 ??的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例?1:

输入: [3,2,3]
输出: 3
示例?2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums)
{
	int len = nums.size();
	int k = len / 2;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < len; i++)
	{
		int j = i;
		while (j < len && nums[j] == nums[i])
		{
			j++;
		}
		if ((j - i) > k)
			return nums[i];
		i = j - 1;
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
	int res = majorityElement(nums);
	cout << res << endl;

	system("pause");
	return 0;
}