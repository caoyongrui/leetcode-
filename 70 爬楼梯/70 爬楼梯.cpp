/*
������������¥�ݡ���Ҫ n?������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������

ʾ�� 1��

���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��
ʾ�� 2��

���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��
*/

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairs1(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	vector<int> nums(n, 0);
	nums[0] = 1;
	nums[1] = 2;
	for (int i = 2; i < n; i++)
	{
		nums[i] = nums[i - 1] + nums[i - 2];
	}
	return nums[n - 1];
}

int main()
{
	int n;
	cin >> n;
	int res = climbStairs1(n);
	cout << res << endl;

	system("pause");
	return 0;
}