/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��

ʾ�� 1:

����: [1,2,3,1]
���: true
ʾ�� 2:

����: [1,2,3,4]
���: false
ʾ��?3:

����: [1,1,1,3,3,4,3,2,4,2]
���: true
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0 || len == 1)
		return false;
	set<int> s;
	for (int i = 0; i < len; i++)
	{
		if (s.find(nums[i]) != s.end())
			return true;
		else
			s.insert(nums[i]);
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
	bool res = containsDuplicate(nums);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}