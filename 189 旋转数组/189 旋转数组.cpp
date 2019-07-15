/*
����һ�����飬�������е�Ԫ�������ƶ�?k?��λ�ã�����?k?�ǷǸ�����

ʾ�� 1:

����: [1,2,3,4,5,6,7] �� k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]
ʾ��?2:

����: [-1,-100,3,99] �� k = 2
���: [3,99,-1,-100]
����:
������ת 1 ��: [99,-1,-100,3]
������ת 2 ��: [3,99,-1,-100]
˵��:

�������������Ľ�����������������ֲ�ͬ�ķ������Խ��������⡣
Ҫ��ʹ�ÿռ临�Ӷ�Ϊ?O(1) ��?ԭ��?�㷨��
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