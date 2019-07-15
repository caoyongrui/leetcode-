/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:

����: [0,1,0,3,12]
���: [1,3,12,0,0]
˵��:

������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������
*/

#include <iostream>
#include <vector>
using namespace std;

//��0Ԫ��ǰ��
void moveZeroes(vector<int>& nums)
{
	int len = nums.size();
	if (!len || len == 1)
		return;
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] != 0)
			nums[k++] = nums[i];
	}
	while (k < len)
	{
		nums[k++] = 0;
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
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}