/*
��дһ�������жϸ��������Ƿ�Ϊ������

��������ֻ����������?2, 3, 5?����������

ʾ�� 1:

����: 6
���: true
����: 6 = 2 ��?3
ʾ�� 2:

����: 8
���: true
����: 8 = 2 �� 2 ��?2
ʾ��?3:

����: 14
���: false
����: 14 ���ǳ�������Ϊ������������һ��������?7��
˵����

1?�ǳ�����
���벻�ᳬ�� 32 λ�з��������ķ�Χ:?[?231,? 231?? 1]��
*/

#include <iostream>
#include <vector>
using namespace std;

bool isUgly(int num)
{
	if (num == 1)
		return true;
	if (num == 0)
		return false;
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;
	return num == 1;
}

int main()
{
	bool res = isUgly(8);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}