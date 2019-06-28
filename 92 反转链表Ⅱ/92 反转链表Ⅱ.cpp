/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤?m?≤?n?≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//将待反转段加入到新建链表中，反转链表使用前插法
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (!head)
		return{};
	ListNode* headNode = new ListNode(0);
	headNode->next = head;
	ListNode* pre = headNode;
	for (int i = 0; i < m - 1; i++)
		pre = pre->next;
	ListNode* cur = pre->next;
	ListNode* lastNext = cur;
	for (int i = 0; i <= n - m; i++)
		lastNext = lastNext->next;
	ListNode* newNode = new ListNode(0);
	ListNode* curNext;
	ListNode* last = cur;
	while (cur != lastNext)
	{
		curNext = cur->next;
		cur->next = newNode->next;
		newNode->next = cur;
		cur = curNext;
	}
	last->next = lastNext;
	pre->next = newNode->next;
	delete newNode;
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
	int m;
	cin >> m >> n;
	ListNode* res = reverseBetween(head->next, m, n);
	while (res)
	{
		if (res->next)
			cout << res->val << "->";
		else
			cout << res->val << endl;
		res = res->next;
	}

	system("pause");
	return 0;
}