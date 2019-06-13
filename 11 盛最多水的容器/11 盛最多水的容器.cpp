/*
���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ���������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)���ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��

˵�����㲻����б�������� n ��ֵ����Ϊ 2��
ʾ��:

����: [1,8,6,2,5,4,8,3,7]
���: 49
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

//˫ָ�뷨
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