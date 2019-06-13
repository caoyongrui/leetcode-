/*
����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�

���磬�������� nums = [-1��2��1��-4], �� target = 1.

�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() < 3)
	{
		return 0;
	}
	int closest = INT_MAX;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++)
	{
		int num1 = nums[i];
		if (num1 > target && abs(target - num1 - nums[i + 1] - nums[i + 2]) > abs(closest - target))
		{
			break;
		}
		for (int j = i + 1; j < nums.size() - 1; j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				closest = abs(target - num1 - nums[j] - nums[k]) < abs(target - closest) ? (num1 + nums[j] + nums[k]) : closest;
			}
		}
	}
	return closest;
}

//˫ָ����ײ��
int threeSumClosest1(vector<int>& nums, int target)
{
	if (nums.size() < 3)
	{
		return 0;
	}
	sort(nums.begin(), nums.end());
	int closest = INT_MAX;
	for (int i = 0; i < nums.size(); i++)
	{
		int num1 = nums[i];
		int j = i + 1;
		int k = nums.size() - 1;
		while (j < k)
		{
			if (num1 + nums[j] + nums[k] == target)
			{
				return target;
			}
			else if (num1 + nums[j] + nums[k] < target)
			{
				closest = abs(target - num1 - nums[j] - nums[k]) < abs(target - closest) ? (num1 + nums[j] + nums[k]) : closest;
				j++;
			}
			else
			{
				closest = abs(target - num1 - nums[j] - nums[k]) < abs(target - closest) ? (num1 + nums[j] + nums[k]) : closest;
				k--;
			}
		}
	}
	return closest;
}

int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-4);
	int res = threeSumClosest1(nums, 1);
	cout << res << endl;

	system("pause");
	return 0;
}