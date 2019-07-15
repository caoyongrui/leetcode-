/*
����һ������?n?���������������һ��������?s ���ҳ���������������� �� s �ĳ�����С�����������顣��������ڷ������������������飬���� 0��

ʾ��:?

����: s = 7, nums = [2,3,1,2,4,3]
���: 2
����: ������?[4,3]?�Ǹ������µĳ�����С�����������顣
����:

������Ѿ������O(n) ʱ�临�ӶȵĽⷨ, �볢��?O(n log n) ʱ�临�ӶȵĽⷨ��
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
	int minLen = INT32_MAX;
	int len = nums.size();
	int sum;
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += nums[k];
			}
			if (sum >= s)
				minLen = min(minLen, j - i + 1);
		}
	}
	return minLen == INT32_MAX ? 0 : minLen;
}

//�������ڽⷨ
int minSubArrayLen1(int s, vector<int>& nums)
{
	int len = nums.size();
	int start = 0;
	int end = 0;
	int minLen = INT32_MAX;
	int sum = 0;
	while (end < len)
	{
		if (sum + nums[end] < s)
		{
			sum += nums[end++];
		}
		else
		{
			minLen = min((end - start + 1), minLen);
			sum -= nums[start++];
		}
	}
	return minLen == INT32_MAX ? 0 : minLen;
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
	cin >> n;
	int res = minSubArrayLen1(n, nums);
	cout << res << endl;

	system("pause");
	return 0;
}