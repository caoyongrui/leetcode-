/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val)
{
	if (!head)
		return head;
	ListNode* headNode = new ListNode(0);
	headNode->next = head;
	ListNode* curPre = headNode;
	ListNode* cur = head;
	ListNode* delNode;
	while (cur)
	{
		if (cur->val == val)
		{
			delNode = cur;
			curPre->next = cur->next;
			cur = curPre->next;
			delete delNode;
			continue;
		}
		curPre = curPre->next;
		cur = curPre->next;
	}
	return headNode->next;
}

int main()
{
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	int n;
	while (cin >> n)
	{
		cur->next = new ListNode(n);
		cur = cur->next;
		if (cin.get() == '\n')
			break;
	}
	cin >> n;
	ListNode* res = removeElements(head->next, n);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}