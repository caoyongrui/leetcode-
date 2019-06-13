/*
����?n?�����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�

���磬����?n = 3�����ɽ��Ϊ��

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void helper(string cur, vector<string> &res, int n, int left, int right)
{
	//��Ϊright�������ţ�����=n ������ʱ�Ѿ��ҵ�һ�����
	if (right == n)
	{
		res.push_back(cur);
	}
	//�������һ��������
	if (left < n)
	{
		helper(cur + '(', res, n, left + 1, right);
	}
	//���һ��������
	if (right < left)
	{
		helper(cur + ')', res, n, left, right + 1);
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> res;
	helper("", res, n, 0, 0);
	return res;
}

int main()
{
	vector<string> res = generateParenthesis(3);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}

	system("pause");
	return 0;
}