/*
����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 1:

���� nums = [3,2,2,3], val = 3,

����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ�� 2:

���� nums = [0,1,2,2,3,0,4,2], val = 2,

����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��

ע�������Ԫ�ؿ�Ϊ����˳��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
˵��:

Ϊʲô������ֵ��������������Ĵ���������?

��ע�⣬�����������ԡ����á���ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�

����������ڲ���������:

// nums ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
int len = removeElement(nums, val);

// �ں������޸�����������ڵ������ǿɼ��ġ�
// ������ĺ������صĳ���, �����ӡ�������иó��ȷ�Χ�ڵ�����Ԫ�ء�
for (int i = 0; i < len; i++) {
print(nums[i]);
}
*/

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == val)
		{
			for (int j = i + 1; j < len; j++)
			{
				nums[j - 1] = nums[j];
			}
			len--;
			i--;
		}
	}
	return len;
}

//˫ָ�뷨
int removeElement1(vector<int>& nums, int val)
{
	int i = 0;
	int j = 0;
	for (; j < nums.size(); j++)
	{
		if (nums[j] != val)
		{
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(0);
	v.push_back(4);
	v.push_back(2);
	int res = removeElement1(v, 2);
	for (int i = 0; i < res; i++)
	{
		cout << v[i] << " ";
	}

	system("pause");
	return 0;
}