/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
	if (!head)
		return head;
	ListNode* nullP = NULL;
	ListNode* cur = head;
	ListNode* curNext;
	while (cur)
	{
		curNext = cur->next;
		cur->next = nullP;
		nullP = cur;
		cur = curNext;
	}
	return nullP;
}

//改变前后指针指向
ListNode* reverseList1(ListNode* head)
{
	if (!head)
		return head;
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* last = NULL;
	while (cur)
	{
		last = cur->next;
		cur->next = pre;
		pre = cur;
		cur = last;
	}
	return pre;
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
	ListNode* res = reverseList1(head->next);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}