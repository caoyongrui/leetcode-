/*
����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

˵��:?Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
���������� [3,9,20,null,null,15,7]��

	3
   / \
  9  20
  /  \
 15   7
��������������?3 ��
*/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	stack<TreeNode*> s;
	stack<int> dep;
	s.push(root);
	dep.push(1);
	int maxDep = 0;
	while (!s.empty())
	{
		TreeNode* node = s.top();
		s.pop();
		int temp = dep.top();
		dep.pop();
		maxDep = temp > maxDep ? temp : maxDep;
		if (node->right)
		{
			s.push(node->right);
			dep.push(temp + 1);
		}
		if (node->left)
		{
			s.push(node->left);
			dep.push(temp + 1);
		}	
	}
	return maxDep;
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
	int res = maxDepth(root);
	cout << res << endl;

	system("pause");
	return 0;
}