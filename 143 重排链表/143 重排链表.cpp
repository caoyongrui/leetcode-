/*
����һ��������?L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

ʾ��?1:

�������� 1->2->3->4, ��������Ϊ 1->4->2->3.
ʾ�� 2:

�������� 1->2->3->4->5, ��������Ϊ 1->5->2->4->3.
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//ʹ�ÿ���ָ���ҵ������е㣬�ָ��������������ã�Ȼ���������ǰ�����
void reorderList(ListNode* head)
{
	if (!head || !head->next)
		return;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* last = slow->next;
	slow->next = NULL;
	ListNode* lastTemp = NULL;
	ListNode* lastNext;
	while (last)
	{
		lastNext = last->next;
		last->next = lastTemp;
		lastTemp = last;
		last = lastNext;
	}
	ListNode* preTemp = head;
	ListNode* lastTempNext;
	while (lastTemp)
	{
		lastTempNext = lastTemp->next;
		lastTemp->next = preTemp->next;
		preTemp->next = lastTemp;
		preTemp = lastTemp->next;
		lastTemp = lastTempNext;
	}
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
	reorderList(head->next);
	while (head->next)
	{
		cout << head->next->val << ' ';
		head->next = head->next->next;
	}
	cout << endl;

	system("pause");
	return 0;
}