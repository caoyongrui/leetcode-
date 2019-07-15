/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例?1:

输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例?2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

#include <iostream>
#include <vector>
using namespace std;

bool jumpZero(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > (v.size() - 1 - i))
			return true;
	}
	return false;
}

bool canJump(vector<int>& nums)
{
	if (nums.size() <= 1)
		return true;
	if (nums[0] == 0)
		return false;
	for (int i = 1; i < nums.size() - 1; i++)
	{
		if (nums[i] == 0)
		{
			vector<int> v{ nums.begin(), nums.begin() + i + 1 };
			if (!jumpZero(v))
				return false;
		}
	}
	return true;
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
	bool res = canJump(nums);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}