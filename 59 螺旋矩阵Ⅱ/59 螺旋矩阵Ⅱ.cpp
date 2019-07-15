/*
����һ��������?n������һ������ 1 ��?n2?����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���

ʾ��:

����: 3
���:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> res( n, vector<int>(n, 0) );
	if (!n)
		return res;
	int a1 = 0, a2 = n - 1;
	int b1 = 0, b2 = n - 1;
	int k = 1;
	while (a1 <= a2 && b1 <= b2)
	{
		for (int i = b1; i <= b2; i++)
			res[a1][i] = k++;
		for (int i = a1 + 1; i <= a2; i++)
			res[i][b2] = k++;
		if (a1 < a2 && b1 < b2)
		{
			for (int i = b2 - 1; i >= b1; i--)
				res[a2][i] = k++;
			for (int i = a2 - 1; i > a1; i--)
				res[i][b1] = k++;
		}
		a1++;
		a2--;
		b1++;
		b2--;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> res = generateMatrix(n);
	cout << '[' << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << '[';
		for (int j = 0; j < res[0].size(); j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;

	system("pause");
	return 0;
}