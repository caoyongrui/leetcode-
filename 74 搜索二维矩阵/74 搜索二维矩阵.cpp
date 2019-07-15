/*
��дһ����Ч���㷨���ж�?m x n?�����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�

ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
ʾ��?1:

����:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 3
���: true
ʾ��?2:

����:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 13
���: false
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