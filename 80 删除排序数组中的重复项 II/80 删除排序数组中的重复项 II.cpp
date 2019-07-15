/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

ʾ��?1:

���� nums = [1,1,1,2,2,3],

����Ӧ�����³��� length = 5, ����ԭ�����ǰ���Ԫ�ر��޸�Ϊ 1, 1, 2, 2, 3 ��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ��?2:

���� nums = [0,0,1,1,1,1,2,3,3],

����Ӧ�����³��� length = 7, ����ԭ�����ǰ���Ԫ�ر��޸�Ϊ?0, 0, 1, 1, 2, 3, 3 ��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() <= 1)
		return nums.size();
	int current = 1;
	for (int i = 2; i < nums.size(); i++)
	{
		if (nums[i] != nums[current - 1])
			nums[++current] = nums[i];
	}
	return current + 1;
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
	int len = removeDuplicates(nums);
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}