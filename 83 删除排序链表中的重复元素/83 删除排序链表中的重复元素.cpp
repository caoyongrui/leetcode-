/*
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ��?1:

����: 1->1->2
���: 1->2
ʾ��?2:

����: 1->1->2->3->3
���: 1->2->3
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