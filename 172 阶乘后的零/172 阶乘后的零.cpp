/*
����һ������ n������ n! ���β�������������

ʾ�� 1:

����: 3
���: 0
����:?3! = 6, β����û���㡣
ʾ��?2:

����: 5
���: 1
����:?5! = 120, β������ 1 ����.
˵��: ���㷨��ʱ�临�Ӷ�ӦΪ?O(log?n)?��
*/

#include <iostream>
using namespace std;

int trailingZeroes(int n)
{
	int res = 0;
	while (n >= 5)
	{
		res += n / 5;
		n /= 5;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int res = trailingZeroes(n);
	cout << res << endl;

	system("pause");
	return 0;
}