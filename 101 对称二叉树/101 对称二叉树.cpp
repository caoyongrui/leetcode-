/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树?[1,2,2,3,4,4,3] 是对称的。

	1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个?[1,2,2,null,3,null,3] 则不是镜像对称的:

	1
   / \
  2   2
  \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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