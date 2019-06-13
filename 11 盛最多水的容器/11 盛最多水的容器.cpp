/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height)
{
	int square;
	int length;
	int h;
	int res = 0;
	for (int i = 0; i < height.size(); i++)
	{
		for (int j = i + 1; j < height.size(); j++)
		{
			length = j - i;
			h = min(height[i], height[j]);
			square = length * h;
			res = res > square ? res : square;
		}
	}
	return res;
}

//双指针法
int maxArea1(vector<int>& height)
{
	int i = 0;
	int j = height.size() - 1;
	int square;
	int res = 0;
	while (i < j)
	{
		square = min(height[i], height[j]) * (j - i);
		res = res > square ? res : square;
		if (height[i] <= height[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return res;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(8);
	v.push_back(6);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(8);
	v.push_back(3);
	v.push_back(7);
	int res = maxArea1(v);
	cout << res << endl;

	system("pause");
	return 0;
}