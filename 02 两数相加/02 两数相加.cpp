/*
�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int num;
	ListNode * next;
	ListNode(int x) : num(x), next(NULL) {}
};

int reverse(long x)
{
	long res = 0;
	while (x != 0)
	{
		int a = x % 10;
		x /= 10;
		res = res * 10 + a;
		if (res < -pow(2, 31) || res > pow(2, 31) - 1)
		{
			return 0;
		}
	}
	return res;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	long num1 = 0;
	while (l1 != NULL)
	{
		num1 = num1 * 10 + l1->num;
		l1 = l1->next;
	}
	num1 = reverse(num1);
	cout << num1 << endl;

	long num2 = 0;
	while (l2 != NULL)
	{
		num2 = num2 * 10 + l2->num;
		l2 = l2->next;
	}
	num2 = reverse(num2);
	cout << num2 << endl;

	long res = num1 + num2;
	cout << res << endl;
	int temp = 0;
	ListNode * resList = new ListNode(0);
	ListNode * l3 = resList;
	if (res == 0)
	{
		return l3;
	}
	while (res != 0)
	{
		temp = res % 10;
		res /= 10;
		ListNode * node = new ListNode(temp);
		resList->next = node;
		resList = node;
	}
	return l3->next;
}

ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2)
{
	ListNode* curNode = l1;
	int temp = 0;
	int val = 0;
	int num = 0;
	while (curNode->next != NULL && l2->next != NULL)
	{
		num = curNode->num + l2->num + temp;
		val = num % 10;
		curNode->num = val;
		temp = num / 10;
		curNode = curNode->next;
		l2 = l2->next;
	}
	if (l2->next == NULL && curNode->next == NULL)
	{
		num = curNode->num + l2->num + temp;
		val = num % 10;
		curNode->num = val;
		temp = num / 10;
		if (temp != 0)
		{
			ListNode* node = new ListNode(temp);
			curNode->next = node;
		}
	}
	else if (l2->next == NULL)
	{
		num = curNode->num + l2->num + temp;
		val = num % 10;
		curNode->num = val;
		temp = num / 10;
		curNode = curNode->next;
		num = curNode->num + temp;
		val = num % 10;
		curNode->num = val;
		temp = num / 10;
		if (temp != 0 && curNode->next == NULL)
		{
			ListNode* node = new ListNode(temp);
			curNode->next = node;
		}
		else if (curNode->next != NULL)
		{
			curNode = curNode->next;
			curNode->num += temp;
		}
	}
	else
	{
		num = curNode->num + l2->num + temp;
		val = num % 10;
		curNode->num = val;
		temp = num / 10;
		curNode->next = l2->next;
		curNode = curNode->next;
		num = curNode->num + temp;
		val = num % 10;
		curNode->num = val;
		temp = num / 10;
		if (temp != 0 && curNode->next == NULL)
		{
			ListNode* node = new ListNode(temp);
			curNode->next = node;
		}
		else if (curNode->next != NULL)
		{
			curNode = curNode->next;
			curNode->num += temp;
		}
	}
	return l1;
}

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
{
	ListNode* l3 = new ListNode(0);
	ListNode* resList = l3;
	int num1;
	int num2;
	int temp = 0;
	int sum;
	while (l1 != NULL || l2 != NULL)
	{
		if (l1 == NULL)
		{
			num1 = 0;
			sum = num1 + l2->num + temp;
			ListNode* node = new ListNode(sum % 10);
			temp = sum / 10;
			l2 = l2->next;
			l3->next = node;
			l3 = l3->next;
			continue;
		}
		else if (l2 == NULL)
		{
			num2 = 0;
			sum = l1->num + num2 + temp;
			ListNode* node = new ListNode(sum % 10);
			temp = sum / 10;
			l1 = l1->next;
			l3->next = node;
			l3 = l3->next;
			continue;
		}
		sum = l1->num + l2->num + temp;
		ListNode* node = new ListNode(sum % 10);
		temp = sum / 10;
		l1 = l1->next;
		l2 = l2->next;
		l3->next = node;
		l3 = l3->next;
	}
	if (temp != 0)
	{
		ListNode* node = new ListNode(temp);
		l3->next = node;
	}
	return resList->next;
}

int main()
{
	ListNode * l1 = new ListNode(9);

	ListNode * l2 = new ListNode(9);
	ListNode * node3 = new ListNode(9);
	l2->next = node3;

	//ListNode * resList = addTwoNumbers1(l2, l1);
	//ListNode * resList = addTwoNumbers(l1, l2);
	ListNode * resList = addTwoNumbers2(l1, l2);
	ListNode * curNode = resList;
	while (curNode != NULL)
	{
		if (curNode->next != NULL)
		{
			cout << curNode->num << "->";
		}
		else
		{
			cout << curNode->num;
		}
		curNode = curNode->next;
	}
	cout << endl;

	system("pause");
	return 0;
}