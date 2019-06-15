/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

����㷨ʱ�临�Ӷȱ�����?O(log n) ����

��������в�����Ŀ��ֵ������?[-1, -1]��

ʾ�� 1:

����: nums = [5,7,7,8,8,10], target = 8
���: [3,4]
ʾ��?2:

����: nums = [5,7,7,8,8,10], target = 6
���: [-1,-1]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
	int start = 0;
	int end = nums.size() - 1;
	vector<int> res;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (target == nums[mid])
		{
			while (mid >= start && nums[mid] == target)
			{
				mid--;
			}
			res.push_back(mid + 1);
			mid = (start + end) / 2;
			while (mid <= end && nums[mid] == target)
			{
				mid++;
			}
			res.push_back(mid - 1);
			return res;
		}
		else if (target > nums[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return{ -1, -1};
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
	int target;
	cin >> target;
	vector<int> res = searchRange(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}