/*
给定一个链表，删除链表的倒数第?n?个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n?保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (n == 0)
	{
		return head;
	}
	ListNode node(0);
	node.next = head;
	ListNode* curNode = head;
	ListNode* preNode = &node;
	ListNode* lastNode = head;
	int i = 1;
	while (i < n)
	{
		lastNode = lastNode->next;
		i++;
	}
	while (lastNode->next != NULL)
	{
		preNode = preNode->next;
		curNode = preNode->next;
		lastNode = lastNode->next;
	}
	preNode->next = curNode->next;
	return node.next;
}

int main()
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	int n = 5;
	ListNode* res = removeNthFromEnd(&node1, n);
	while (res != NULL)
	{
		if (res->next != NULL)
		{
			cout << res->val << "->";
		}
		else
		{
			cout << res->val << endl;
		}
		res = res->next;
	}

	system("pause");
	return 0;
}