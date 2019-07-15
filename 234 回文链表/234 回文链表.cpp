/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用?O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//快慢指针
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