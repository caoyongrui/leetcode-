/*
����һ�����ظ�Ԫ�ص�����?candidates?��һ��Ŀ����?target?���ҳ�?candidates?�����п���ʹ���ֺ�Ϊ?target?����ϡ�

candidates?�е����ֿ����������ظ���ѡȡ��

˵����

�������֣�����?target��������������
�⼯���ܰ����ظ�����ϡ�?
ʾ��?1:

����: candidates = [2,3,6,7], target = 7,
����⼯Ϊ:
[
[7],
[2,2,3]
]
ʾ��?2:

����: candidates = [2,3,5], target = 8,
����⼯Ϊ:
[
? [2,2,2,2],
  [2,3,3],
  [3,5]
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
			temp.push_back(candidates[i]);
			combinationDfs(candidates, target - candidates[i], temp, res, i);
			temp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<int> temp;
	vector<vector<int>> res;
	if (candidates.size() == 0)
	{
		return{};
	}
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
	vector<vector<int>> res = combinationSum(candidates, target);
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