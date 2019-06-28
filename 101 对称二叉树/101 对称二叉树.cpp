/*
����һ����������������Ƿ��Ǿ���ԳƵġ�

���磬������?[1,2,2,3,4,4,3] �ǶԳƵġ�

	1
   / \
  2   2
 / \ / \
3  4 4  3
�����������?[1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

	1
   / \
  2   2
  \   \
   3    3
˵��:

�����������õݹ�͵������ַ������������⣬��ܼӷ֡�
*/

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;
	return (p->val == q->val) && helper(p->left, q->right) && helper(p->right, q->left);
}

bool isSymmetric(TreeNode* root)
{
	return helper(root, root);
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
	bool res = isSymmetric(root);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}