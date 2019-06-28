/*
给定一个链表，旋转链表，将链表每个节点向右移动?k?个位置，其中?k?是非负数。

示例?1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例?2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步:?0->1->2->NULL
向右旋转 4 步:?2->0->1->NULL
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
	if (!head)
		return{};
	int len = 0;
	ListNode* curNode = head;
	while (curNode)
	{
		len++;
		curNode = curNode->next;
	}
	int moveStep = k % len;
	ListNode* pre = head;
	ListNode* last = pre;
	for (int i = 1; i < moveStep + 1; i++)
	{
		last = last->next;
	}
	while (last->next)
	{
		pre = pre->next;
		last = last->next;
	}
	last->next = head;
	head = pre->next;
	pre->next = NULL;
	return head;
}

int main()
{
	ListNode* head = new ListNode(0);
	ListNode* curNode = head;
	int n;
	while (cin >> n)
	{
		curNode->next = new ListNode(n);
		curNode = curNode->next;
		if (cin.get() == '\n')
			break;
	}
	int k;
	cin >> k;
	ListNode* res = rotateRight(head->next, k);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}