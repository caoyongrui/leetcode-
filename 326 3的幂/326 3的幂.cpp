/*
����һ��������дһ���������ж����Ƿ��� 3?���ݴη���

ʾ�� 1:

����: 27
���: true
ʾ�� 2:

����: 0
���: false
ʾ�� 3:

����: 9
���: true
ʾ�� 4:

����: 45
���: false
���ף�
���ܲ�ʹ��ѭ�����ߵݹ�����ɱ�����
*/

#include <iostream>
using namespace std;

bool isPowerOfThree(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (pow(3, i) == n)
			return true;
		else if (pow(3, i) > n)
			return false;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	bool res = isPowerOfThree(n);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}