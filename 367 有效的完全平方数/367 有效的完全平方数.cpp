/*
����һ�������� num����дһ����������� num ��һ����ȫƽ�������򷵻� True�����򷵻� False��

˵������Ҫʹ���κ����õĿ⺯������? sqrt��

ʾ�� 1��

���룺16
�����True
ʾ�� 2��

���룺14
�����False
*/

#include <iostream>
using namespace std;

bool isPerfectSquare(int num)
{
	int start = 0;
	int end = num;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (pow(mid, 2) == num)
			return true;
		else if (pow(mid, 2) < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
}

int main()
{
	int num;
	cin >> num;
	bool res = isPerfectSquare(num);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}