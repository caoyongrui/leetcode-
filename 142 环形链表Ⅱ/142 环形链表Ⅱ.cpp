/*
给定一个链表，返回链表开始入环的第一个节点。?如果链表无环，则返回?null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

?

 示例 1：

 输入：head = [3,2,0,-4], pos = 1
 输出：tail connects to node index 1
 解释：链表中有一个环，其尾部连接到第二个节点。


 示例?2：

 输入：head = [1,2], pos = 0
 输出：tail connects to node index 0
 解释：链表中有一个环，其尾部连接到第一个节点。


 示例 3：

 输入：head = [1], pos = -1
 输出：no cycle
 解释：链表中没有环。


 ?

  进阶：
  你是否可以不用额外空间解决此题？
*/

#include <iostream>
#include <set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//哈希表法，需要额外空间
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