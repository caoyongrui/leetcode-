/*
����һ��δ������������飬�ҳ�����û�г��ֵ���С����������

ʾ��?1:

����: [1,2,0]
���: 3
ʾ��?2:

����: [3,4,-1,1]
���: 2
ʾ��?3:

����: [7,8,9,11,12]
���: 1
˵��:

����㷨��ʱ�临�Ӷ�ӦΪO(n)������ֻ��ʹ�ó�������Ŀռ䡣
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int i = 0;
	for (; i < nums.size(); i++)
	{
		if (nums[i] == 1)
			break;
	}
	if (i == nums.size())
		return 1;
	i++;
	int num = 1;
	for (; i < nums.size(); i++)
	{
		if (nums[i] == num)
			continue;
		num++;
		if (nums[i] != num)
			return num;
	}
	return num + 1;
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
	int res = firstMissingPositive(nums);
	cout << res << endl;

	system("pause");
	return 0;
}