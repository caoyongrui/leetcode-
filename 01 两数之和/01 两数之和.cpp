/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

/*
1.暴力法，双重循环
2.使用容器map，遍历一遍的同时将索引及值放入到map中
*/

#include <iostream>
#include <vector>
using namespace std;
#include <map>

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> v(2, -1); //初始化两个-1值
	for (int i = 0; i < nums.size() - 1; i++) //细节，最后一个不用找，因为已经没有j可找了
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				v.push_back(i);
				v.push_back(j);
			}
		}
	}
	return v;
}

vector<int> twoSum2(vector<int>& nums, int target)
{
	map<int, int> m;
	vector<int> v(2, -1);
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.count(target - nums[i]) > 0)
		{
			v[0] = m[target - nums[i]];
			v[1] = i;
			break;
		}
		m.insert(make_pair(nums[i], i));
	}
	return v;
}

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);
	/*vector<int> v1 = twoSum(v, 9);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << (*it) << endl;
	}*/

	vector<int> v2 = twoSum2(v, 18);
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << (*it) << endl;
	}

	system("pause");
	return 0;
}