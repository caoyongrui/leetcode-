/*
��ֵԪ����ָ��ֵ������������ֵ��Ԫ�ء�

����һ����������?nums������ nums[i] �� nums[i+1]���ҵ���ֵԪ�ز�������������

������ܰ��������ֵ������������£������κ�һ����ֵ����λ�ü��ɡ�

����Լ���?nums[-1] = nums[n] = -�ޡ�

ʾ�� 1:

����: nums = [1,2,3,1]
���: 2
����: 3 �Ƿ�ֵԪ�أ���ĺ���Ӧ�÷��������� 2��
ʾ��?2:

����: nums = [1,2,1,3,5,6,4]
���: 1 �� 5
����: ��ĺ������Է������� 1�����ֵԪ��Ϊ 2��
?    ���߷������� 5�� ���ֵԪ��Ϊ 6��
˵��:

��ĽⷨӦ����?O(logN)?ʱ�临�Ӷȵġ�
*/

#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums)
{
	int len = nums.size();
	if (!len)
		return{};
	if (len == 1)
		return 0;
	int i = 0;
	int j = len - 1;
	while (i < j)
	{
		int mid = (i + j) / 2;
		if (nums[mid] < nums[mid + 1])
			i = mid + 1;
		else
			j = mid;
	}
	return i;
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
	int res = findPeakElement(nums);
	cout << res << endl;

	system("pause");
	return 0;
}