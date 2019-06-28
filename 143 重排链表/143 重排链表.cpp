/*
给定一个单链表?L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例?1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//使用快慢指针找到链表中点，分割链表，将后半段逆置，然后逐个插入前半段中
void reorderList(ListNode* head)
{
	if (!head || !head->next)
		return;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* last = slow->next;
	slow->next = NULL;
	ListNode* lastTemp = NULL;
	ListNode* lastNext;
	while (last)
	{
		lastNext = last->next;
		last->next = lastTemp;
		lastTemp = last;
		last = lastNext;
	}
	ListNode* preTemp = head;
	ListNode* lastTempNext;
	while (lastTemp)
	{
		lastTempNext = lastTemp->next;
		lastTemp->next = preTemp->next;
		preTemp->next = lastTemp;
		preTemp = lastTemp->next;
		lastTemp = lastTempNext;
	}
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
	reorderList(head->next);
	while (head->next)
	{
		cout << head->next->val << ' ';
		head->next = head->next->next;
	}
	cout << endl;

	system("pause");
	return 0;
}