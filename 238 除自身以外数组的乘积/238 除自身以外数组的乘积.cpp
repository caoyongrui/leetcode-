/*
��������Ϊ?n?����������?nums������?n > 1�������������?output?������ output[i]?����?nums?�г�?nums[i]?֮�������Ԫ�صĳ˻���

ʾ��:

����: [1,2,3,4]
���: [24,12,8,6]
˵��: �벻Ҫʹ�ó���������?O(n) ʱ�临�Ӷ�����ɴ��⡣

���ף�
������ڳ����ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��
*/

#include <iostream>
#include <vector>
using namespace std;

//���α���
vector<int> productExceptSelf(vector<int>& nums)
{
	int len = nums.size();
	vector<int> res(len, 0);
	int left = 1;
	int right = 1;
	for (int i = 0; i < len; i++)
	{
		res[i] = left;
		left *= nums[i];
	}
	for (int i = len - 1; i >= 0; i--)
	{
		res[i] *= right;
		right *= nums[i];
	}
	return res;
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
	vector<int> res = productExceptSelf(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}