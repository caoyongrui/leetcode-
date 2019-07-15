/*
编写一个高效的算法来判断?m x n?矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例?1:

输入:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 3
输出: true
示例?2:

输入:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 13
输出: false
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (!matrix.size())
		return false;
	int col = matrix[0].size();
	if (!col)
		return false;
	int i = 0;
	while (i < matrix.size() - 1)
	{
		if (target >= matrix[i][0] && target < matrix[i + 1][0])
			break;
		i++;
	}
	if (target >= matrix[i][0] && target <= matrix[i][col - 1])
	{
		int j = 0;
		int k = col - 1;
		while (j <= k)
		{
			int mid = (j + k) / 2;
			if (matrix[i][mid] == target)
				return true;
			else if (matrix[i][mid] < target)
				j = mid + 1;
			else
				k = mid - 1;
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix{
		{ 1, 3, 5, 7 },
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};
	int target = 21;
	bool res = searchMatrix(matrix, target);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}