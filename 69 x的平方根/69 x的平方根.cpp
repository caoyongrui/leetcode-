/*
ʵ��?int sqrt(int x)?������

���㲢����?x?��ƽ����������?x �ǷǸ�������

���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:

����: 4
���: 2
ʾ�� 2:

����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842...,
���ڷ���������������С�����ֽ�����ȥ
*/

#include <iostream>
using namespace std;

//���ֲ���
int mySqrt(int x)
{
	int i = 0;
	int j = x / 2 + 1; //�κηǸ�����ƽ�����������x / 2 + 1
	while (i <= j)
	{
		int mid = (i + j) / 2;
		if (x == mid * mid)
		{
			return mid;
		}
		else if (x > mid * mid)
		{
			i = mid + 1;
		}
		else
		{
			j = mid - 1;
		}
	}
	return j;
}

//ţ�ٷ�
int mySqrt1(int x)
{
	if (x == 0)
	{
		return 0;
	}
	double temp = 0;
	double res = 1;
	while (temp != res)
	{
		temp = res;
		res = (res + x / res) / 2;
	}
	return (int)res;
}

int main()
{
	int res = mySqrt(0);
	cout << res << endl;

	system("pause");
	return 0;
}