/*
����һ������ɾ������ĵ�����?n?���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����

������ n?��֤����Ч�ġ�

���ף�

���ܳ���ʹ��һ��ɨ��ʵ����
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