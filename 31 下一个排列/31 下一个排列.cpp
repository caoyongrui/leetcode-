/*
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�

�����������һ����������У��������������г���С�����У����������У���

����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int>& nums, int i)
{
	int j = nums.size() - 1;
	while (i < j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		i++;
		j--;
	}
}

void nextPermutation(vector<int>& nums)
{
	int i;
	int j;
	int len = nums.size();
	for (i = len - 1; i > 0; i--)
	{
		if (nums[i] > nums[i - 1])
		{
			break;
		}
	}
	if (i == 0)
	{
		sort(nums.begin(), nums.end());
	}
	else
	{
		for (j = len - 1; j >= i; j--)
		{
			if (nums[j] > nums[i - 1])
			{
				break;
			}
		}
		int temp = nums[i - 1];
		nums[i - 1] = nums[j];
		nums[j] = temp;
		reverse(nums, i);
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
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}