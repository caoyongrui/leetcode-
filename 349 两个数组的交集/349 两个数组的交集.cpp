/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	set<int> s1;
	set<int> s2;
	for (int i = 0; i < nums1.size(); i++)
	{
		s1.insert(nums1[i]);
	}
	for (int i = 0; i < nums2.size(); i++)
	{
		s2.insert(nums2[i]);
	}
	int len1 = s1.size();
	int len2 = s2.size();
	vector<int> res;
	set<int>::iterator it = s1.begin();
	set<int>::iterator jt = s2.begin();
	if (len1 <= len2)
	{
		while (it != s1.end())
		{
			if (s2.find(*it) != s2.end())
			{
				res.push_back(*it);
			}
			it++;
		}
	}
	else
	{
		while (jt != s2.end())
		{
			if (s1.find(*jt) != s1.end())
				res.push_back(*jt);
			jt++;
		}
	}
	return res;
}

int main()
{
	vector<int> nums1;
	vector<int> nums2;
	int n;
	while (cin >> n)
	{
		nums1.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	while (cin >> n)
	{
		nums2.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	vector<int> res = intersection(nums1, nums2);
	for (auto i : res)
	{
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}