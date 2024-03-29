/*
给定一个非负整数?numRows，生成杨辉三角的前?numRows?行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> res(numRows);
	if (numRows == 0)
		return res;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				res[i].push_back(1);
			else
				res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
		}
	}
	return res;
}

int main()
{
	int numRows;
	cin >> numRows;
	vector<vector<int>> res = generate(numRows);
	cout << '[' << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << '[';
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;

	system("pause");
	return 0;
}