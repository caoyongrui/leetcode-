/*
����һ��������ɫ����ɫ����ɫ��һ��?n ��Ԫ�ص����飬ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�

�����У�����ʹ������ 0��?1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��

ע��:
����ʹ�ô�����е����������������⡣

ʾ��:

����: [2,0,2,1,1,0]
���: [0,0,1,1,2,2]
���ף�

һ��ֱ�۵Ľ��������ʹ�ü������������ɨ���㷨��
���ȣ����������0��1 �� 2 Ԫ�صĸ�����Ȼ����0��1��2��������д��ǰ���顣
�������һ����ʹ�ó����ռ��һ��ɨ���㷨��
*/

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums)
{
	int start = 0;
	int tail = nums.size() - 1;
	int i = 0;
	while (i <= tail)
	{
		if (nums[i] == 0)
			swap(nums[i], nums[start++]);
		if (nums[i] == 2)
			swap(nums[i--], nums[tail--]);
		i++;
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
	sortColors(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}