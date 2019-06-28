/*
����һ������?candidates?��һ��Ŀ����?target?���ҳ�?candidates?�����п���ʹ���ֺ�Ϊ?target?����ϡ�

candidates?�е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�

˵����

�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ�?
ʾ��?1:

����: candidates =?[10,1,2,7,6,1,5], target =?8,
����⼯Ϊ:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
ʾ��?2:

����: candidates =?[2,5,2,1,2], target =?5,
����⼯Ϊ:
[
[1,2,2],
[5]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationDfs(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& res, int start)
{
	if (target < 0)
	{
		return;
	}
	else if (target == 0)
	{
		res.push_back(temp);
	}
	else
	{
		for (int i = start; i < candidates.size(); i++)
		{
			if (i > start && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			temp.push_back(candidates[i]);
			combinationDfs(candidates, target - candidates[i], temp, res, i + 1);
			temp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	if (candidates.size() == 0)
	{
		return{};
	}
	vector<int> temp;
	vector<vector<int>> res;
	sort(candidates.begin(), candidates.end());
	combinationDfs(candidates, target, temp, res, 0);
	return res;
}

int main()
{
	int n;
	vector<int> candidates;
	while (cin >> n)
	{
		candidates.push_back(n);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	int target;
	cin >> target;
	vector<vector<int>> res = combinationSum2(candidates, target);
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