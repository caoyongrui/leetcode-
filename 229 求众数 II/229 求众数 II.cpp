/*
给定一个大小为?n?的数组，找出其中所有出现超过?? n/3 ??次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例?1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
	int len = nums.size();
	int n = len / 3;
	vector<int> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < len; i++)
	{
		int j = i;
		int count = 0;
		while (j < len && nums[j] == nums[i])
		{
			j++;
			count++;
		}
		if (count > n)
			res.push_back(nums[i]);
		i = j - 1;
	}
	return res;
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
	vector<int> res = majorityElement(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}