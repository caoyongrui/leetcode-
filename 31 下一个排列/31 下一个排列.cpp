/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int>& nums, int i)
{
	int j = nums.size() - 1;
	while (i < j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		i++;
		j--;
	}
}

void nextPermutation(vector<int>& nums)
{
	int i;
	int j;
	int len = nums.size();
	for (i = len - 1; i > 0; i--)
	{
		if (nums[i] > nums[i - 1])
		{
			break;
		}
	}
	if (i == 0)
	{
		sort(nums.begin(), nums.end());
	}
	else
	{
		for (j = len - 1; j >= i; j--)
		{
			if (nums[j] > nums[i - 1])
			{
				break;
			}
		}
		int temp = nums[i - 1];
		nums[i - 1] = nums[j];
		nums[j] = temp;
		reverse(nums, i);
	}
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
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}