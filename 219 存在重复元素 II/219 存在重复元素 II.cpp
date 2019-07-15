/*
����һ�����������һ������?k���ж��������Ƿ����������ͬ������?i?��?j��ʹ��?nums [i] = nums [j]������ i �� j?�Ĳ�ľ���ֵ���Ϊ k��

ʾ��?1:

����: nums = [1,2,3,1], k = 3
���: true
ʾ�� 2:

����: nums = [1,0,1,1], k = 1
���: true
ʾ�� 3:

����: nums = [1,2,3,1,2,3], k = 2
���: false
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	int len = nums.size();
	if (len == 0 || len == 1)
		return false;
	map<int, int> m;
	for (int i = 0; i < len; i++)
	{
		if (m.find(nums[i]) == m.end())
			m.insert(make_pair(nums[i], i));
		else
		{
			if ((i - m[nums[i]]) <= k)
				return true;
			else
				m[nums[i]] = i;
		}
	}
	return false;
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
	bool res = containsNearbyDuplicate(nums, n);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}