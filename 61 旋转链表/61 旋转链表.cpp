/*
����һ��������ת����������ÿ���ڵ������ƶ�?k?��λ�ã�����?k?�ǷǸ�����

ʾ��?1:

����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
ʾ��?2:

����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL
����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��:?0->1->2->NULL
������ת 4 ��:?2->0->1->NULL
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