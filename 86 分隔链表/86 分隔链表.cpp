/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x)
{
	ListNode* beforeNode = new ListNode(0);
	ListNode* before = beforeNode;
	ListNode* afterNode = new ListNode(0);
	ListNode* after = afterNode;
	while (head)
	{
		if (head->val < x)
		{
			before->next = head;
			before = before->next;
		}
		else
		{
			after->next = head;
			after = after->next;
		}
		head = head->next;
	}
	after->next = NULL;
	before->next = afterNode->next;
	return beforeNode->next;
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
	int x;
	cin >> x;
	ListNode* res = partition(head->next, x);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}