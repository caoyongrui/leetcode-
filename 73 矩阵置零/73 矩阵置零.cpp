/*
给定一个?m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例?1:

输入:
[
[1,1,1],
[1,0,1],
[1,1,1]
]
输出:
[
[1,0,1],
[0,0,0],
[1,0,1]
]
示例?2:

输入:
[
[0,1,2,0],
[3,4,5,2],
[1,3,1,5]
]
输出:
[
[0,0,0,0],
[0,4,5,0],
[0,3,1,0]
]
进阶:

一个直接的解决方案是使用 ?O(mn)?的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m?+?n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？
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