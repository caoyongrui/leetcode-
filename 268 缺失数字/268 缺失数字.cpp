/*
����һ������ 0, 1, 2, ..., n?��?n?���������У��ҳ� 0 .. n?��û�г����������е��Ǹ�����

ʾ�� 1:

����: [3,0,1]
���: 2
ʾ��?2:

����: [9,6,4,2,3,5,7,0,1]
���: 8
˵��:
����㷨Ӧ��������ʱ�临�Ӷȡ����ܷ��ʹ�ö��ⳣ���ռ���ʵ��?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums)
{
	int len = nums.size();
	sort(nums.begin(), nums.end());
	if (len == 1)
		return nums[0] == 0 ? 1 : 0;
	int i = 1;
	while (i < len)
	{
		if (nums[i - 1] + 1 != nums[i])
			return (nums[i - 1] + 1);
		i++;
	}
	return nums[0] == 0 ? len : 0;
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
	int res = missingNumber(nums);
	cout << res << endl;

	system("pause");
	return 0;
}