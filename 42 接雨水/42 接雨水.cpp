/*
给定?n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。?感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

#include <iostream>
#include <vector>
using namespace std;

//装满雨水后呈梯形，找到峰值，峰值左右两侧呈上升趋势。分别从两边开始，往塔顶所在位置遍历，水位只会增高不会减小，且一直和最近遇到的最大高度持平，这样知道了实时水位，就可以边遍历边计算面积。
int trap(vector<int>& height)
{
	int max = -1;
	int index = 0;
	int len = height.size();
	if (len <= 2)
		return 0;
	for (int i = 0; i < len; i++)
	{
		if (height[i] > max)
		{
			max = height[i];
			index = i;
		}
	}
	int temp = height[0];
	int res = 0;
	for (int i = 0; i < index; i++)
	{
		if (height[i] > temp)
			temp = height[i];
		else
			res += temp - height[i];
	}
	temp = height[len - 1];
	for (int i = len - 1; i > index; i--)
	{
		if (height[i] > temp)
			temp = height[i];
		else
			res += temp - height[i];
	}
	return res;
}

int main()
{
	vector<int> height;
	int n;
	while (cin >> n)
	{
		height.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int res = trap(height);
	cout << res << endl;

	system("pause");
	return 0;
}