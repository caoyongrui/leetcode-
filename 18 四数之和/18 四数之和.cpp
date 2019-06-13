/*
给定一个包含?n 个整数的数组?nums?和一个目标值?target，判断?nums?中是否存在四个元素 a，b，c?和 d?，使得?a + b + c + d?的值与?target?相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	if (nums.size() < 4)
	{
		return{};
	}
	vector<vector<int>> res;
	set<vector<int>> s;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 3; i++)
	{
		if (nums[i] > target && target > 0)
			break;
		for (int j = i + 1; j < nums.size() - 2; j++)
		{
			int k = j + 1;
			int l = nums.size() - 1;
			while (k < l)
			{
				if (nums[i] + nums[j] + nums[k] + nums[l] == target)
				{
					vector<int> temp{ nums[i], nums[j], nums[k], nums[l] };
					s.insert(temp);
					k++;
					l--;
				}
				else if (nums[i] + nums[j] + nums[k] + nums[l] < target)
				{
					k++;
				}
				else
				{
					l--;
				}
			}
		}
	}
	for (auto c : s)
	{
		res.push_back(c);
	}
	return res;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(2);
	int target = 0;
	vector<vector<int>> res = fourSum(nums, target);
	cout << '[' << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << '[';
		for (int j = 0; j < res[i].size(); j++)
		{
			if (j == res[i].size() - 1)
			{
				cout << res[i][j];
			}
			else
			{
				cout << res[i][j] << ',';
			}
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;

	system("pause");
	return 0;
}