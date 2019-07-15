/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例?3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0 || len == 1)
		return false;
	set<int> s;
	for (int i = 0; i < len; i++)
	{
		if (s.find(nums[i]) != s.end())
			return true;
		else
			s.insert(nums[i]);
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
	bool res = containsDuplicate(nums);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}