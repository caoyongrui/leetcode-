/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* l3 = new ListNode(0);
	ListNode* resList = l3;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			l3->next = l1;
			l3 = l3->next;
			l1 = l1->next;
		}
		else
		{
			l3->next = l2;
			l3 = l3->next;
			l2 = l2->next;
		}
	}
	if (l1 != NULL)
	{
		l3->next = l1;
	}
	else if (l2 != NULL)
	{
		l3->next = l2;
	}
	return resList->next;
}

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	l1->next = node1;
	ListNode* node2 = new ListNode(4);
	node1->next = node2;

	ListNode* l2 = new ListNode(4);
	ListNode* node3 = new ListNode(5);
	l2->next = node3;
	ListNode* node4 = new ListNode(6);
	node3->next = node4;

	ListNode* resNode = mergeTwoLists(l1, l2);
	while (resNode != NULL)
	{
		if (resNode->next != NULL)
		{
			cout << resNode->val << "->";
		}
		else
		{
			cout << resNode->val << endl;
		}
		resNode = resNode->next;
	}

	system("pause");
	return 0;
}