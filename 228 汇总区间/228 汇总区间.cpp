/*
����һ�����ظ�Ԫ�ص������������飬�����������䷶Χ�Ļ��ܡ�

ʾ�� 1:

����: [0,1,2,4,5,7]
���: ["0->2","4->5","7"]
����: 0,1,2 �����һ������������;?4,5 �����һ�����������䡣
ʾ�� 2:

����: [0,2,3,4,6,8,9]
���: ["0","2->4","6","8->9"]
����: 2,3,4 �����һ������������;?8,9 �����һ�����������䡣
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
	int len = nums.size();
	vector<string> res;
	if (!len)
		return res;
	if (len == 1)
	{
		res.push_back(to_string(nums[0]));
		return res;
	}
	nums.push_back(INT32_MAX);
	len++;
	for (int i = 0; i < len; i++)
	{
		long long temp = 0;
		for (int k = i; k < len; k++)
		{
			string s;
			long long sub = (long long)nums[k] - (long long)nums[i];
			if (sub != temp)
			{
				if (k - i == 1)
					s = to_string(nums[i]);
				else
					s = to_string(nums[i]) + "->" + to_string(nums[k - 1]);
				res.push_back(s);
				i = k - 1;
				break;
			}
			else
				temp++;
		}
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
	vector<string> res = summaryRanges(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}