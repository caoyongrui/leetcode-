/*
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

ʾ��?1:

����: [1,2,3]
���: [1,2,4]
����: ���������ʾ���� 123��
ʾ��?2:

����: [4,3,2,1]
���: [4,3,2,2]
����: ���������ʾ���� 4321��
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	vector<int> res = digits;
	int temp = 0;
	int num;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (i == digits.size() - 1)
		{
			num = digits[i] + 1;	
		}
		else
		{
			num = digits[i] + temp;
		}
		temp = num / 10;
		res[i] = num % 10;
	}
	if (temp)
	{
		/*res.clear();
		res.push_back(1);
		for (int i = 0; i < digits.size(); i++)
		{
			res.push_back(0);
		}*/
		res.insert(res.begin(), 1);
	}
	return res;
}

int main()
{
	vector<int> digits;
	int n;
	while (cin >> n)
	{
		digits.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	vector<int> res = plusOne(digits);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}