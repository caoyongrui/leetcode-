/*
给定一个数组，将数组中的元素向右移动?k?个位置，其中?k?是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例?2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为?O(1) 的?原地?算法。
*/

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums, int i, int j)
{
	int temp;
	while (i < j)
	{
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		i++;
		j--;
	}
}

void rotate(vector<int>& nums, int k)
{
	int len = nums.size();
	if (!len)
		return;
	int step = k % len;
	reverse(nums, 0, len - 1 - step);
	reverse(nums, len - step, len - 1);
	reverse(nums, 0, len - 1);
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
	int k;
	cin >> k;
	rotate(nums, k);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}