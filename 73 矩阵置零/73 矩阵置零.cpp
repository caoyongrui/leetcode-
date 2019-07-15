/*
����һ��?m x n �ľ������һ��Ԫ��Ϊ 0�����������к��е�����Ԫ�ض���Ϊ 0����ʹ��ԭ���㷨��

ʾ��?1:

����:
[
[1,1,1],
[1,0,1],
[1,1,1]
]
���:
[
[1,0,1],
[0,0,0],
[1,0,1]
]
ʾ��?2:

����:
[
[0,1,2,0],
[3,4,5,2],
[1,3,1,5]
]
���:
[
[0,0,0,0],
[0,4,5,0],
[0,3,1,0]
]
����:

һ��ֱ�ӵĽ��������ʹ�� ?O(mn)?�Ķ���ռ䣬���Ⲣ����һ���õĽ��������
һ���򵥵ĸĽ�������ʹ�� O(m?+?n) �Ķ���ռ䣬������Ȼ������õĽ��������
�������һ�������ռ�Ľ��������
*/

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
	int rowLen = matrix.size();
	if (rowLen == 0)
		return;
	int colLen = matrix[0].size();
	if (colLen == 0)
		return;
	vector<int> col(colLen, 0);
	vector<int> row(rowLen, 0);
	for (int i = 0; i < rowLen; i++)
	{
		for (int j = 0; j < colLen; j++)
		{
			if (matrix[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for (int i = 0; i < rowLen; i++)
	{
		for (int j = 0; j < colLen; j++)
		{
			if (row[i] == 1)
				matrix[i][j] = 0;
			else if (col[j] == 1)
				matrix[i][j] = 0;
		}
	}
}

int main()
{
	vector<vector<int>> matrix{
		{0, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 1, 5}
	};
	setZeroes(matrix);
	cout << '[' << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << '[';
		for (int j = 0; j < matrix[0].size(); j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;

	system("pause");
	return 0;
}