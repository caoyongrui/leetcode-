/*
����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

ʾ��:

����: head = 1->4->3->2->5->2, x = 3
���: 1->2->2->4->3->5
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