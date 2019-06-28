/*
��������в�������


��������Ķ�����ʾ���ϡ��ӵ�һ��Ԫ�ؿ�ʼ����������Ա���Ϊ�Ѿ����������ú�ɫ��ʾ����
ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ��ú�ɫ��ʾ������ԭ�ؽ�����뵽���ź���������С�

?

 ���������㷨��

 ���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
 ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
 �ظ�ֱ�������������ݲ�����Ϊֹ��
 ?

  ʾ�� 1��

  ����: 4->2->1->3
  ���: 1->2->3->4
  ʾ��?2��

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

ListNode* insertionSortList(ListNode* head)
{
	if (!head || !head->next)
		return head;
	ListNode* headNode = new ListNode(0);
	headNode->next = head;
	ListNode* curPre = head;
	ListNode* cur = curPre->next;
	ListNode* sortedPre;
	ListNode* sortedCur;
	while (cur)
	{
		sortedPre = headNode;
		sortedCur = sortedPre->next;
		while (sortedCur != cur && sortedCur->val < cur->val)
		{
			sortedPre = sortedPre->next;
			sortedCur = sortedPre->next;
		}
		if (sortedCur == cur)
		{
			curPre = curPre->next;
			cur = curPre->next;
		}
		else
		{
			curPre->next = cur->next;
			cur->next = sortedCur;
			sortedPre->next = cur;
			cur = curPre->next;
		}
	}
	return headNode->next;
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
	ListNode* res = insertionSortList(head->next);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}