/*
����һ���������� ?nums��������������?i?��?j??(i?��?j) ��Χ��Ԫ�ص��ܺͣ�����?i,? j?���㡣

ʾ����

���� nums = [-2, 0, 3, -5, 2, -1]����ͺ���Ϊ sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
˵��:

����Լ������鲻�ɱ䡣
���ε���?sumRange?������
*/

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	vector<int> num;

	NumArray(vector<int>& nums) {
		num.push_back(0);
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			num.push_back(sum);
		}
	}

	int sumRange(int i, int j) {
		return num[j + 1] - num[i];
	}
};

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
	NumArray* obj = new NumArray(nums);
	int i, j;
	cin >> i >> j;
	int res = obj->sumRange(i, j);
	cout << res << endl;

	system("pause");
	return 0;
}