/*
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

ʾ�� 1:

����: 123
���: 321
ʾ�� 2:

����: -123
���: -321
ʾ�� 3:

����: 120
���: 21
ע��:

�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ [?231,  231 ? 1]�������������裬�����ת�����������ô�ͷ��� 0��
*/
/*
1.��ת������ʹ��long����Ϊ���������еĺܴ�
2.pow()����ʹ��
*/

#include <iostream>
using namespace std;
#include <cmath>

int reverse(int x)
{
	long long res = 0;
	while (x != 0)
	{
		int a = x % 10;
		x /= 10;
		res = res * 10 + a;
		if (res < INT_MIN || res > INT_MAX)
		{
			return 0;
		}
	}
	return (int)res;
}

int main()
{
	int res = reverse(INT_MIN);
	cout << res << endl;

	system("pause");
	return 0;
}