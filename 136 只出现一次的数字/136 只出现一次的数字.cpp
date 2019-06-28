/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例?2:

输入: [4,1,2,1,2]
输出: 4
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

//哈希表法
int singleNumber(vector<int>& nums)
{
	set<int> s;
	for (int i = 0; i < nums.size(); i++)
	{
		if (s.find(nums[i]) == s.end())
			s.insert(nums[i]);
		else
			s.erase(nums[i]);
	}
	return *s.begin();
}

//位操作a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
int singleNumber1(vector<int>& nums)
{
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		res = res ^ nums[i];
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
	int res = singleNumber1(nums);
	cout << res << endl;

	system("pause");
	return 0;
}