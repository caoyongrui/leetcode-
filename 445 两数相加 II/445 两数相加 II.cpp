/*
���������ǿ����������������Ǹ��������������λλ������ʼλ�á����ǵ�ÿ���ڵ�ֻ�洢�������֡�����������ӻ᷵��һ���µ�����

?

 ����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��

 ����:

 ��������������޸ĸ���δ������仰˵���㲻�ܶ��б��еĽڵ���з�ת��

 ʾ��:

 ����: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 ���: 7 -> 8 -> 0 -> 7
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head)
{
	ListNode* p = NULL;
	ListNode* headNext;
	while (head)
	{
		headNext = head->next;
		head->next = p;
		p = head;
		head = headNext;
	}
	return p;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	l1 = reverse(l1);
	l2 = reverse(l2);
	int n = 0;
	int temp = 0;
	ListNode* headNode = new ListNode(0);
	headNode->next = l1;
	ListNode* cur = l1;
	ListNode* curPre = headNode;
	while (cur && l2)
	{
		n = cur->val + l2->val + temp;
		cur->val = n % 10;
		temp = n / 10;
		curPre = curPre->next;
		cur = curPre->next;
		l2 = l2->next;
	}
	if (cur)
	{
		while (cur)
		{
			if (temp)
			{
				n = cur->val + temp;
				cur->val = n % 10;
				temp = n / 10;
				cur = cur->next;
			}
			else
				break;
		}
	}
	if (l2)
	{
		curPre->next = l2;
		while (l2)
		{
			if (temp)
			{
				n = l2->val + temp;
				l2->val = n % 10;
				temp = n / 10;
				l2 = l2->next;
			}
			else
				break;
		}
	}
	if (temp)
	{
		ListNode* node = new ListNode(temp);
		l1 = reverse(l1);
		node->next = l1;
		return node;
	}
	return reverse(l1);
}

//��������ջ
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2)
{
	stack<int> s1, s2;
	ListNode* cur = l1;
	while (cur)
	{
		s1.push(cur->val);
		cur = cur->next;
	}
	cur = l2;
	while (cur)
	{
		s2.push(cur->val);
		cur = cur->next;
	}
	ListNode* nullP = NULL;
	int temp = 0;
	int val = 0;
	while (!s1.empty() && !s2.empty())
	{
		val = s1.top() + s2.top() + temp;
		temp = val / 10;
		ListNode* node = new ListNode(val % 10);
		node->next = nullP;
		nullP = node;
		s1.pop();
		s2.pop();
	}
	while (!s1.empty())
	{
		val = s1.top() + temp;
		temp = val / 10;
		ListNode* node = new ListNode(val % 10);
		node->next = nullP;
		nullP = node;
		s1.pop();
	}
	while (!s2.empty())
	{
		val = s2.top() + temp;
		temp = val / 10;
		ListNode* node = new ListNode(val % 10);
		node->next = nullP;
		nullP = node;
		s2.pop();
	}
	if (temp)
	{
		ListNode* node = new ListNode(temp);
		node->next = nullP;
		nullP = node;
	}
	return nullP;
}

int main()
{
	ListNode* l1 = new ListNode(0);
	ListNode* cur = l1;
	int n;
	while (cin >> n)
	{
		cur->next = new ListNode(n);
		cur = cur->next;
		if (cin.get() == '\n')
			break;
	}
	ListNode* l2 = new ListNode(0);
	cur = l2;
	while (cin >> n)
	{
		cur->next = new ListNode(n);
		cur = cur->next;
		if (cin.get() == '\n')
			break;
	}
	ListNode* res = addTwoNumbers1(l1->next, l2->next);
	while (res)
	{
		cout << res->val << ' ';
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}