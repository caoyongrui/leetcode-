/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定数组 nums = [1,1,2],

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
print(nums[i]);
}
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (nums[j] == nums[i])
			{
				for (int k = j + 1; k < len; k++)
				{
					nums[k - 1] = nums[k];
				}
				len--;
				j--;
			}
		}
	}
	return len;
}

//双指针法
int removeDuplicates1(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	int i = 0;
	int j = 1;
	while (j < nums.size())
	{
		if (nums[j] != nums[i])
		{
			nums[++i] = nums[j];
			j++;
		}
		else
		{
			j++;
		}
	}
	return i + 1;
}

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	int res = removeDuplicates1(v);
	for (int i = 0; i < res; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}