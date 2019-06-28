/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中?没有重复出现?的数字。

示例?1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例?2:

输入: 1->1->1->2->3
输出: 2->3
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	if (!head)
		return{};
	ListNode* cur = head;
	ListNode* pre = head;
	ListNode* last;
	while (cur)
	{
		last = cur->next;
		while (last && last->val == cur->val)
		{
			last = last->next;
		}
		if (cur == head && cur->next != last)
		{
			head = last;
			cur = head;
		}	
		else if(cur == head && cur->next == last)
		{
			pre = cur;
			cur = pre->next;
		}
		else if (cur->next != last)
		{
			pre->next = last;
			cur = last;
		}
		else if (cur->next == last)
		{
			pre = pre->next;
			cur = pre->next;
		}
	}
	return head;
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
	ListNode* res = deleteDuplicates(head->next);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}