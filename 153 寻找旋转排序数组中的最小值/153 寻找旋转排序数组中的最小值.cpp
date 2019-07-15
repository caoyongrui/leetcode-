/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬����?[0,1,2,4,5,6,7] ���ܱ�Ϊ?[4,5,6,7,0,1,2]?)��

���ҳ�������С��Ԫ�ء�

����Լ��������в������ظ�Ԫ�ء�

ʾ�� 1:

����: [3,4,5,1,2]
���: 1
ʾ�� 2:

����: [4,5,6,7,0,1,2]
���: 0
*/

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
	if (nums.size() == 0)
		return {};
	if (nums.size() == 1)
		return nums[0];
	int i = 0;
	int j = nums.size() - 1;
	if (nums[i] < nums[j])
		return nums[0];
	while (i <= j)
	{
		int mid = (i + j) / 2;
		if (nums[mid] > nums[mid + 1])
			return nums[mid + 1];
		if (nums[mid] > nums[0])
			i = mid;
		else
			j = mid;
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
	int res = findMin(nums);
	cout << res << endl;

	system("pause");
	return 0;
}