/*
����һ������?n + 1 ������������?nums�������ֶ��� 1 �� n?֮�䣨���� 1 �� n������֪���ٴ���һ���ظ�������������ֻ��һ���ظ����������ҳ�����ظ�������

ʾ�� 1:

����: [1,3,4,2,2]
���: 2
ʾ�� 2:

����: [3,1,3,4,2]
���: 3
˵����

���ܸ���ԭ���飨����������ֻ���ģ���
ֻ��ʹ�ö���� O(1) �Ŀռ䡣
ʱ�临�Ӷ�С�� O(n2) ��
������ֻ��һ���ظ������֣��������ܲ�ֹ�ظ�����һ�Ρ�
*/

#include <iostream>
#include <vector>
using namespace std;

//�ض��ɻ���ʹ�ÿ���ָ��
int findDuplicate(vector<int>& nums)
{
	int len = nums.size();
	int fast = 0;
	int slow = 0;
	while (true)
	{
		fast = nums[nums[fast]];
		slow = nums[slow];
		if (fast == slow)
		{
			fast = 0;
			while (fast != slow)
			{
				fast = nums[fast];
				slow = nums[slow];
			}
			return fast;
		}
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
	int res = findDuplicate(nums);
	cout << res << endl;

	system("pause");
	return 0;
}