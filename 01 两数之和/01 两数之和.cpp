/*
����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
*/

/*
1.��������˫��ѭ��
2.ʹ������map������һ���ͬʱ��������ֵ���뵽map��
*/

#include <iostream>
#include <vector>
using namespace std;
#include <map>

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> v(2, -1); //��ʼ������-1ֵ
	for (int i = 0; i < nums.size() - 1; i++) //ϸ�ڣ����һ�������ң���Ϊ�Ѿ�û��j������
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				v.push_back(i);
				v.push_back(j);
			}
		}
	}
	return v;
}

vector<int> twoSum2(vector<int>& nums, int target)
{
	map<int, int> m;
	vector<int> v(2, -1);
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.count(target - nums[i]) > 0)
		{
			v[0] = m[target - nums[i]];
			v[1] = i;
			break;
		}
		m.insert(make_pair(nums[i], i));
	}
	return v;
}

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);
	/*vector<int> v1 = twoSum(v, 9);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << (*it) << endl;
	}*/

	vector<int> v2 = twoSum2(v, 18);
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << (*it) << endl;
	}

	system("pause");
	return 0;
}