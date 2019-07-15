/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ��λ�á�

ʾ��?1:

����: [2,3,1,1,4]
���: true
����: ��λ�� 0 �� 1 �� 1 ��, Ȼ���� 3 ���������һ��λ�á�
ʾ��?2:

����: [3,2,1,0,4]
���: false
����: �������������ܻᵽ������Ϊ 3 ��λ�á�����λ�õ������Ծ������ 0 �� ��������Զ�����ܵ������һ��λ�á�
*/

#include <iostream>
#include <vector>
using namespace std;

bool jumpZero(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > (v.size() - 1 - i))
			return true;
	}
	return false;
}

bool canJump(vector<int>& nums)
{
	if (nums.size() <= 1)
		return true;
	if (nums[0] == 0)
		return false;
	for (int i = 1; i < nums.size() - 1; i++)
	{
		if (nums[i] == 0)
		{
			vector<int> v{ nums.begin(), nums.begin() + i + 1 };
			if (!jumpZero(v))
				return false;
		}
	}
	return true;
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
	bool res = canJump(nums);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}