/*
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�

�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

ʾ�� 1:

����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
ʾ�� 2:

����: 2->1->3->5->6->4->7->NULL
���: 2->3->6->7->1->5->4->NULL
˵��:

Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head)
{
	if (!head || !head->next)
		return head;
	ListNode* cur = head;
	ListNode* oddNode = new ListNode(0);
	ListNode* odd = oddNode;
	ListNode* evenNode = new ListNode(0);
	ListNode* even = evenNode;
	int n = 0;
	while (cur)
	{
		n++;
		if (n % 2 == 1)
		{
			odd->next = cur;
			odd = odd->next;
		}
		else
		{
			even->next = cur;
			even = even->next;
		}
		cur = cur->next;
	}
	even->next = NULL;
	odd->next = evenNode->next;
	delete evenNode;
	odd = oddNode->next;
	ListNode* p = oddNode;
	delete p;
	return odd;
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
	ListNode* res = oddEvenList(head->next);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}