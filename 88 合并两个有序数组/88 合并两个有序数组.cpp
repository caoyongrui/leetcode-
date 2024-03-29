/*
给定两个有序整数数组?nums1 和 nums2，将 nums2 合并到?nums1?中，使得?num1 成为一个有序数组。

说明:

初始化?nums1 和 nums2 的元素数量分别为?m 和 n。
你可以假设?nums1?有足够的空间（空间大小大于或等于?m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出:?[1,2,2,3,5,6]
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> nums3(nums1.begin(), nums1.begin() + m);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < m && j < n)
	{
		if (nums3[i] <= nums2[j])
		{
			nums1[k] = nums3[i];
			i++;
		}
		else
		{
			nums1[k] = nums2[j];
			j++;
		}
		k++;
	}
	if (i < m)
	{
		while (i < m)
		{
			nums1[k] = nums3[i];
			i++;
			k++;
		}
	}
	if (j < n)
	{
		while (j < n)
		{
			nums1[k] = nums2[j];
			j++;
			k++;
		}
	}
}

int main()
{
	vector<int> nums1;
	int k;
	while (cin >> k)
	{
		nums1.push_back(k);
		if (cin.get() == '\n')
			break;
	}
	int m;
	cin >> m;
	vector<int> nums2;
	while (cin >> k)
	{
		nums2.push_back(k);
		if (cin.get() == '\n')
			break;
	}
	int n;
	cin >> n;
	merge(nums1, m, nums2, n);
	for (int i = 0; i < m + n; i++)
	{
		cout << nums1[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}