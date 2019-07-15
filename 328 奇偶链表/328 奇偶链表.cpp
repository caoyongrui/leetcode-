/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
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