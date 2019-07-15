/*
给定一个包含 0, 1, 2, ..., n?中?n?个数的序列，找出 0 .. n?中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例?2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums)
{
	int len = nums.size();
	sort(nums.begin(), nums.end());
	if (len == 1)
		return nums[0] == 0 ? 1 : 0;
	int i = 1;
	while (i < len)
	{
		if (nums[i - 1] + 1 != nums[i])
			return (nums[i - 1] + 1);
		i++;
	}
	return nums[0] == 0 ? len : 0;
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
	int res = missingNumber(nums);
	cout << res << endl;

	system("pause");
	return 0;
}