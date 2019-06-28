/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1:

����: [2,2,1]
���: 1
ʾ��?2:

����: [4,1,2,1,2]
���: 4
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

//��ϣ��
int singleNumber(vector<int>& nums)
{
	set<int> s;
	for (int i = 0; i < nums.size(); i++)
	{
		if (s.find(nums[i]) == s.end())
			s.insert(nums[i]);
		else
			s.erase(nums[i]);
	}
	return *s.begin();
}

//λ����a��b��a=(a��a)��b=0��b=b
int singleNumber1(vector<int>& nums)
{
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		res = res ^ nums[i];
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
	int res = singleNumber1(nums);
	cout << res << endl;

	system("pause");
	return 0;
}