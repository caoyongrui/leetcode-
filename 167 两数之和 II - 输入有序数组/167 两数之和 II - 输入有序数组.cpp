/*
给定一个已按照升序排列?的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1?必须小于?index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> res;
	bool state = false;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				res.push_back(i + 1);
				res.push_back(j + 1);
				state = true;
				break;
			}
		}
		if (state == true)
			break;
	}
	return res;
}

//二分查找
vector<int> twoSum1(vector<int>& numbers, int target)
{
	vector<int> res;
	bool state = false;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		int k = i + 1;
		int j = numbers.size() - 1;
		while (k <= j)
		{
			int mid = (k + j) / 2;
			if (numbers[mid] + numbers[i] == target)
			{
				res.push_back(i + 1);
				res.push_back(mid + 1);
				state = true;
				break;
			}
			else if (numbers[mid] + numbers[i] < target)
			{
				k = mid + 1;
			}
			else
				j = mid - 1;
		}
		if (state == true)
			break;
	}
	return res;
}

int main()
{
	vector<int> numbers;
	int n;
	while (cin >> n)
	{
		numbers.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int target;
	cin >> target;
	vector<int> res = twoSum1(numbers, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}