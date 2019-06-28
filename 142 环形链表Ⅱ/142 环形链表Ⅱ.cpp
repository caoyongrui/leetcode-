/*
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣?��������޻����򷵻�?null��

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

˵�����������޸ĸ���������

?

 ʾ�� 1��

 ���룺head = [3,2,0,-4], pos = 1
 �����tail connects to node index 1
 ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣


 ʾ��?2��

 ���룺head = [1,2], pos = 0
 �����tail connects to node index 0
 ���ͣ���������һ��������β�����ӵ���һ���ڵ㡣


 ʾ�� 3��

 ���룺head = [1], pos = -1
 �����no cycle
 ���ͣ�������û�л���


 ?

  ���ף�
  ���Ƿ���Բ��ö���ռ������⣿
*/

#include <iostream>
#include <set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//��ϣ������Ҫ����ռ�
ListNode *detectCycle(ListNode *head)
{
	set<ListNode*> s;
	ListNode* temp = head;
	while (temp)
	{
		if (s.find(temp) == s.end())
		{
			s.insert(temp);
			temp = temp->next;
		}
		else
			return temp;
	}
	return NULL;
}

ListNode *detectCycle1(ListNode *head)
{
	if (!head || !head->next)
		return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			break;
	}
	if (!fast || !fast->next)
		return NULL;
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
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
	int pos;
	cin >> pos;
	if (pos >= 0)
	{
		ListNode* l = head->next;
		for (int i = 0; i < pos; i++)
		{
			l = l->next;
		}
		cur->next = l;
	}
	ListNode* res = detectCycle1(head->next);
	cout << res->val << endl;

	system("pause");
	return 0;
}