/*
����һ���������������������ڵĽڵ㣬�����ؽ����������

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

?

 ʾ��:

 ���� 1->2->3->4, ��Ӧ�÷��� 2->1->4->3.
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode node(0);
	node.next = head;
	ListNode* p = &node;
	ListNode* pre;
	ListNode* last;
	while (p->next && p->next->next)
	{
		pre = p->next;
		last = pre->next;
		pre->next = last->next;
		last->next = pre;
		p->next = last;
		p = pre;
	}
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
	ListNode* res = swapPairs(&node1);
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}