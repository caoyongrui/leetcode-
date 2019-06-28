/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例?1:

输入: 1->1->2
输出: 1->2
示例?2:

输入: 1->1->2->3->3
输出: 1->2->3
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
	if (head == NULL)
		return{};
	ListNode* cur = head;
	ListNode* p;
	while (cur->next)
	{
		if (cur->next->val == cur->val)
		{
			p = cur->next;
			cur->next = p->next;
			delete p;
			continue;
		}
		cur = cur->next;
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
		if (res->next)
			cout << res->val << "->";
		else
			cout << res->val << endl;
		res = res->next;
	}

	system("pause");
	return 0;
}