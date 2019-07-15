/*
����һ������ļ��ϣ���ϲ������ص������䡣

ʾ�� 1:

����: [[1,3],[2,6],[8,10],[15,18]]
���: [[1,6],[8,10],[15,18]]
����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
ʾ��?2:

����: [[1,4],[4,5]]
���: [[1,5]]
����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByFirst(vector<int> A, vector<int> B)
{
	return A[0] < B[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	int len = intervals.size();
	if (len <= 1)
		return intervals;
	sort(intervals.begin(), intervals.end(), sortByFirst);
	int i = 0;
	while (i < len - 1)
	{
		if (intervals[i][0] <= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][1])
		{
			intervals.erase(intervals.begin() + i + 1);
			len--;
		}
		else if (intervals[i][0] <= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][0])
		{
			intervals[i][1] = intervals[i + 1][1];
			intervals.erase(intervals.begin() + i + 1);
			len--;
		}
		else
			i++;
	}
	return intervals;
}

int main()
{
	vector<vector<int>> intervals{
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18}
	};
	vector<vector<int>> res = merge(intervals);
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