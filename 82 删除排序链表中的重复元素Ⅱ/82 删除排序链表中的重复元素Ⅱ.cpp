/*
����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������?û���ظ�����?�����֡�

ʾ��?1:

����: 1->2->3->3->4->4->5
���: 1->2->5
ʾ��?2:

����: 1->1->1->2->3
���: 2->3
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
	if (!head)
		return{};
	ListNode* cur = head;
	ListNode* pre = head;
	ListNode* last;
	while (cur)
	{
		last = cur->next;
		while (last && last->val == cur->val)
		{
			last = last->next;
		}
		if (cur == head && cur->next != last)
		{
			head = last;
			cur = head;
		}	
		else if(cur == head && cur->next == last)
		{
			pre = cur;
			cur = pre->next;
		}
		else if (cur->next != last)
		{
			pre->next = last;
			cur = last;
		}
		else if (cur->next == last)
		{
			pre = pre->next;
			cur = pre->next;
		}
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
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}