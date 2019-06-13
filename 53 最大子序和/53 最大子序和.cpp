/*
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	int temp = 0;
	int ret = INT_MIN;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i; j < nums.size(); j++)
		{
			temp += nums[j];
			ret = ret > temp ? ret : temp;
		}
		temp = 0;
	}
	return ret;
}

//��̬�滮
int maxSubArray1(vector<int>& nums)
{
	if (nums.size() == 0) return NULL;
	int res = INT_MIN;
	int sum = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum = max(nums[i], sum + nums[i]);
		res = max(sum, res);
	}
	return res;
}

int main()
{
	vector<int> v;
	v.push_back(-2);
	v.push_back(1);
	v.push_back(-3);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-5);
	v.push_back(4);
	int ret = maxSubArray1(v);
	cout << ret << endl;

	system("pause");
	return 0;
}