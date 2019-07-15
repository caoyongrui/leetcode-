/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

#include <iostream>
#include <vector>
using namespace std;

//非0元素前移
void moveZeroes(vector<int>& nums)
{
	int len = nums.size();
	if (!len || len == 1)
		return;
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] != 0)
			nums[k++] = nums[i];
	}
	while (k < len)
	{
		nums[k++] = 0;
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
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}