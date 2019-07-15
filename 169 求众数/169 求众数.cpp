/*
����һ����СΪ n �����飬�ҵ����е�������������ָ�������г��ִ�������?? n/2 ??��Ԫ�ء�

����Լ��������Ƿǿյģ����Ҹ������������Ǵ���������

ʾ��?1:

����: [3,2,3]
���: 3
ʾ��?2:

����: [2,2,1,1,1,2,2]
���: 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums)
{
	int len = nums.size();
	int k = len / 2;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < len; i++)
	{
		int j = i;
		while (j < len && nums[j] == nums[i])
		{
			j++;
		}
		if ((j - i) > k)
			return nums[i];
		i = j - 1;
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
	int res = majorityElement(nums);
	cout << res << endl;

	system("pause");
	return 0;
}