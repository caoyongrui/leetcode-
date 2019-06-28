/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
  /  \
 15   7
返回其自底向上的层次遍历为：

[
[15,7],
[9,20],
[3]
]
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> res;
	if (!root)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int len = q.size();
		vector<int> temp;
		for (int i = 0; i < len; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			temp.push_back(node->val);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		res.insert(res.begin(), temp);
	}
	return res;
}

void createBiTree(TreeNode *&T)
{
	int n;
	cin >> n;
	if (n == NULL)
		T = nullptr;
	else
	{
		T = new TreeNode(n);
		createBiTree(T->left);
		createBiTree(T->right);
	}
}

int main()
{
	TreeNode* root;
	createBiTree(root);
	vector<vector<int>> res = levelOrderBottom(root);
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