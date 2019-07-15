/*
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1:

����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2,2]
ʾ�� 2:

����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [4,9]
˵����

��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
���ǿ��Բ�������������˳��
����:

��������������Ѿ��ź����أ��㽫����Ż�����㷨��
���?nums1?�Ĵ�С��?nums2?С�ܶ࣬���ַ������ţ�
���?nums2?��Ԫ�ش洢�ڴ����ϣ������ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> res;
	vector<int>::iterator it;
	for (int i = 0; i < nums1.size(); i++)
	{
		it = find(nums2.begin(), nums2.end(), nums1[i]);
		if (it != nums2.end())
		{
			res.push_back(*it);
			nums2.erase(it);
		}
	}
	return res;
}

int main()
{
	vector<int> nums1;
	vector<int> nums2;
	int n;
	while (cin >> n)
	{
		nums1.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	while (cin >> n)
	{
		nums2.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	vector<int> res = intersect(nums1, nums2);
	for (auto i : res)
	{
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}