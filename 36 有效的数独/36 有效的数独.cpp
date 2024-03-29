/*
判断一个?9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字?1-9?在每一行只能出现一次。
数字?1-9?在每一列只能出现一次。
数字?1-9?在每一个以粗实线分隔的?3x3?宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用?'.'?表示。

示例?1:

输入:
[
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]
输出: true
示例?2:

输入:
[
["8","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字?1-9?和字符?'.'?。
给定数独永远是?9x9?形式的。
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
	bool res = true;
	int row[9][9] = { 0 }, col[9][9] = { 0 }, Matrix[9][9] = { 0 };
	for (int i = 0; i<9; i++) 
	{
		for (int j = 0; j<9; j++) 
		{
			if (board[i][j] != '.') 
			{
				int num = board[i][j] - '0' - 1;
				row[i][num]++;
				col[j][num]++;
				Matrix[3 * (i / 3) + j / 3][num]++;
				if (row[i][num] == 2 || col[j][num] == 2 || Matrix[3 * (i / 3) + j / 3][num] == 2)
					return false;
			}
		}
	}
	//return res;
	cout << "row:" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << row[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << "col:" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << col[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Matrix:" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << Matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	return res;
}

int main()
{
	vector<vector<char>> board = { { '5','3','.','.','7','.','.','.','.' },
									{ '6','.','.','1','9','5','.','.','.' },
									{ '.','9','8','.','.','.','.','6','.' },
									{ '8','.','.','.','6','.','.','.','3' },
									{ '4','.','.','8','.','3','.','.','1' },
									{ '7','.','.','.','2','.','.','.','6' },
									{ '.','6','.','.','.','.','2','8','.' },
									{ '.','.','.','4','1','9','.','.','5' },
									{ '.','.','.','.','8','.','.','7','9' } };
	bool res = isValidSudoku(board);
	cout << res << endl;

	system("pause");
	return 0;
}