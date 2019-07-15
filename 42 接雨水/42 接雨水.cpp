/*
����?n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��



������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����?��л Marcos ���״�ͼ��

ʾ��:

����: [0,1,0,2,1,0,1,3,2,1,2,1]
���: 6
*/

#include <iostream>
#include <vector>
using namespace std;

//װ����ˮ������Σ��ҵ���ֵ����ֵ����������������ơ��ֱ�����߿�ʼ������������λ�ñ�����ˮλֻ�����߲����С����һֱ��������������߶ȳ�ƽ������֪����ʵʱˮλ���Ϳ��Ա߱����߼��������
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