/*
���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false
ʾ�� 2:

����: 1->2->2->1
���: true
���ף�
���ܷ���?O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//����ָ��
bool isPalindrome(ListNode* head)
{
	if (!head || !head->next)
		return true;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow->next;
	slow = head;
	ListNode* temp = NULL;
	ListNode* fastNext = fast->next;
	while (fast)
	{
		fastNext = fast->next;
		fast->next = temp;
		temp = fast;
		fast = fastNext;
	}
	while (temp)
	{
		if (temp->val != slow->val)
			return false;
		temp = temp->next;
		slow = slow->next;
	}
	return true;
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
	bool res = isPalindrome(head->next);
	cout.setf(iostream::boolalpha);
	cout << res << endl;

	system("pause");
	return 0;
}