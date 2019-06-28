/*
��?O(n?log?n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£��������������

ʾ�� 1:

����: 4->2->1->3
���: 1->2->3->4
ʾ�� 2:

����: -1->5->3->4->0
���: -1->0->3->4->5
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* l1, ListNode* l2)
{
	ListNode* headNode = new ListNode(0);
	ListNode* cur = headNode;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			cur = cur->next;
			l2 = l2->next;
		}
	}
	if (l1)
		cur->next = l1;
	if (l2)
		cur->next = l2;
	return headNode->next;
}


//�鲢����˼��
ListNode* sortList(ListNode* head)
{
	if (!head || !head->next)
		return head;
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* slowPre = head;
	while (fast && fast->next)
	{
		slowPre = head;
		slow = slowPre->next;
		fast = fast->next->next;
	}
	slowPre->next = NULL;
	return merge(sortList(head), sortList(slow));
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
	ListNode* res = sortList(head->next);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}