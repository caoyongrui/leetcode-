/*
����һ����СΪ?n?�����飬�ҳ��������г��ֳ���?? n/3 ??�ε�Ԫ�ء�

˵��: Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1)��

ʾ��?1:

����: [3,2,3]
���: [3]
ʾ�� 2:

����: [1,1,1,3,3,2,2,2]
���: [1,2]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
	int len = nums.size();
	int n = len / 3;
	vector<int> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < len; i++)
	{
		int j = i;
		int count = 0;
		while (j < len && nums[j] == nums[i])
		{
			j++;
			count++;
		}
		if (count > n)
			res.push_back(nums[i]);
		i = j - 1;
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
	vector<int> res = majorityElement(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}