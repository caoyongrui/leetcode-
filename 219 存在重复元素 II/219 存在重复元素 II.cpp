/*
给定一个整数数组和一个整数?k，判断数组中是否存在两个不同的索引?i?和?j，使得?nums [i] = nums [j]，并且 i 和 j?的差的绝对值最大为 k。

示例?1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	int len = nums.size();
	if (len == 0 || len == 1)
		return false;
	map<int, int> m;
	for (int i = 0; i < len; i++)
	{
		if (m.find(nums[i]) == m.end())
			m.insert(make_pair(nums[i], i));
		else
		{
			if ((i - m[nums[i]]) <= k)
				return true;
			else
				m[nums[i]] = i;
		}
	}
	return false;
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
	cin >> n;
	bool res = containsNearbyDuplicate(nums, n);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}