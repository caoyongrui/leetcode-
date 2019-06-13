/*
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣

����, �������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ��
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	vector<int> v;
	vector<int>::iterator it;
	set<vector<int>> s;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0)
		{
			break;
		}
		for (int j = i + 1; j < nums.size(); j++)
		{
			it = find(nums.begin() + j + 1, nums.end(), 0 - nums[i] - nums[j]);
			if (it != nums.end())
			{
				v.push_back(nums[i]);
				v.push_back(nums[j]);
				v.push_back(*it);
				s.insert(v);
			}
			v.clear();
		}
	}
	for (auto a : s)
	{
		res.push_back(a);
	}
	return res;
}


//��ָ�뷨
vector<vector<int>> threeSum1(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	if (nums.empty() || nums.front() > 0 || nums.back() < 0)
	{
		return{};
	}
	vector<vector<int>> res;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0)
		{
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int temp = -nums[i];
		int j = i + 1;
		int k = nums.size() - 1;
		while (j < k)
		{
			if (nums[j] + nums[k] == temp)
			{
				res.push_back(vector<int>{ nums[i], nums[j], nums[k] });
				while (j < k && nums[j] == nums[j + 1])
				{
					j++;
				}
				while (j < k && nums[k] == nums[k - 1])
				{
					k--;
				}
				j++;
				k--;
			}
			else if (nums[j] + nums[k] < temp)
			{
				j++;
			}
			else
			{
				k--;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);
	vector<vector<int>> res = threeSum1(nums);
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