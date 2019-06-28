/*
����һ�������ж��������Ƿ��л���

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

?

 ʾ�� 1��

 ���룺head = [3,2,0,-4], pos = 1
 �����true
 ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣


 ʾ��?2��

 ���룺head = [1,2], pos = 0
 �����true
 ���ͣ���������һ��������β�����ӵ���һ���ڵ㡣


 ʾ�� 3��

 ���룺head = [1], pos = -1
 �����false
 ���ͣ�������û�л���


 ?

  ���ף�

  ������ O(1)�������������ڴ�����������
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//����ָ�뷨
bool hasCycle(ListNode *head)
{
	if (!head || !head->next)
		return false;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
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
	bool res = hasCycle(head->next);
	cout.setf(ios_base::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}