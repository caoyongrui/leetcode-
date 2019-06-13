/*
�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ?O(log(m + n))��

����Լ���?nums1?��?nums2?����ͬʱΪ�ա�

ʾ�� 1:

nums1 = [1, 3]
nums2 = [2]

����λ���� 2.0
ʾ�� 2:

nums1 = [1, 2]
nums2 = [3, 4]

����λ���� (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int len1 = nums1.size();
	int len2 = nums2.size();
	int mid = (len1 + len2 + 1) / 2;
	int i = 0;
	int j = 0;
	double res;
	while (mid && i < len1 && j < len2)
	{
		mid--;
		if (nums1[i] < nums2[j])
		{
			res = nums1[i++];
		}
		else
		{
			res = nums2[j++];
		}
	}
	while (mid && i < len1)
	{
		mid--;
		res = nums1[i++];
	}
	while (mid && j < len2)
	{
		mid--;
		res = nums2[j++];
	}
	if ((len1 + len2) % 2)
	{
		return res;
	}
	else
	{
		int bigger = min(i < len1 ? nums1[i] : INT_MAX, j < len2 ? nums2[j] : INT_MAX);
		return (res + bigger) / 2;
	}
}

int main()
{
	vector<int> nums1;
	/*nums1.push_back(1);
	nums1.push_back(2);*/
	vector<int> nums2;
	nums2.push_back(1);
	double res = findMedianSortedArrays(nums1, nums2);
	cout << res << endl;

	system("pause");
	return 0;
}