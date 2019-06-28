/*
����һ������?m x n?��Ԫ�صľ���m ��, n �У����밴��˳ʱ������˳�򣬷��ؾ����е�����Ԫ�ء�

ʾ��?1:

����:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
���: [1,2,3,6,9,8,7,4,5]
ʾ��?2:

����:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
���: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int row = matrix.size();
	int col = matrix[0].size();
	if (row == 1)
		return matrix[0];
	int r1 = 0, r2 = row - 1;
	int c1 = 0, c2 = col - 1;
	while (r1 <= r2 && c1 <= c2)
	{
		for (int i = c1; i <= c2; i++)
			res.push_back(matrix[r1][i]);
		for (int i = r1 + 1; i <= r2; i++)
			res.push_back(matrix[i][c2]);
		if (r1 < r2 && c1 < c2)
		{
			for (int i = c2 - 1; i >= c1; i--)
				res.push_back(matrix[r2][i]);
			for (int i = r2 - 1; i > r1; i--)
				res.push_back(matrix[i][c1]);
		}
		r1++;
		r2--;
		c1++;
		c2--;
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9,10,11,12 }
	};
	vector<int> res = spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}