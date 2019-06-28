/*
������������������дһ�����������������Ƿ���ͬ��

����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

ʾ��?1:

����:       1         1
		   / \       / \
		  2   3     2   3

		[1,2,3],   [1,2,3]

���: true
ʾ�� 2:

����:      1          1
		   /           \
		  2             2

		[1,2],     [1,null,2]

���: false
ʾ��?3:

����:       1         1
		   / \       / \
		  2   1     1   2

		[1,2,1],   [1,1,2]

���: false
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DLR(TreeNode* p, vector<int>& res)
{
	if (p)
		res.push_back(p->val);
	if (p->left)
		DLR(p->left, res);
	else
		res.push_back(NULL);
	if (p->right)
		DLR(p->right, res);
	else
		res.push_back(NULL);
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
		return true;
	else if (!p || !q)
		return false;
	vector<int> pv;
	DLR(p, pv);
	vector<int> qv;
	DLR(q, qv);
	bool res = false;
	for (int i = 0; i < pv.size(); i++)
	{
		cout << pv[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < qv.size(); i++)
	{
		cout << qv[i] << ' ';
	}
	cout << endl;
	if (pv == qv)
		res = true;
	return res;
}

bool isSameTree1(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
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
	TreeNode* p;
	createBiTree(p);

	TreeNode* q;
	createBiTree(q);

	bool res = isSameTree(p, q);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}