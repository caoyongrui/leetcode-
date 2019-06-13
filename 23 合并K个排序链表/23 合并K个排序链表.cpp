/*
合并?k?个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
? 1->4->5,
? 1->3->4,
? 2->6
]
输出: 1->1->2->3->4->4->5->6
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	vector<int> nums;
	for (int i = 0; i < lists.size(); i++)
	{
		ListNode* p = lists[i];
		while (p)
		{
			nums.push_back(p->val);
			p = p->next;
		}
	}
	sort(nums.begin(), nums.end());
	ListNode head(0);
	ListNode* cur = &head;
	for (int i = 0; i < nums.size(); i++)
	{
		//循环创建节点需要使用new开辟内存，否则会使用同一地址空间
		/*ListNode node(nums[i]);
		cur->next = &node;*/
		cur->next = new ListNode(nums[i]);
		cur = cur->next;
	}
	return head.next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* l3 = new ListNode(0);
	ListNode* resList = l3;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			l3->next = l1;
			l3 = l3->next;
			l1 = l1->next;
		}
		else
		{
			l3->next = l2;
			l3 = l3->next;
			l2 = l2->next;
		}
	}
	if (l1 != NULL)
	{
		l3->next = l1;
	}
	else if (l2 != NULL)
	{
		l3->next = l2;
	}
	return resList->next;
}

//分治法，两两结合
ListNode* mergeKLists1(vector<ListNode*>& lists)
{
	int num = lists.size();
	int interval = 1;
	while (interval < num)
	{
		for (int i = 0; i < num - interval; i += 2 * interval)
		{
			lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
		}
		interval *= 2;
	}
	return lists[0];
}

int main()
{
	ListNode l1(1);
	ListNode node1(4);
	ListNode node2(5);
	l1.next = &node1;
	node1.next = &node2;

	ListNode l2(1);
	ListNode node3(3);
	ListNode node4(4);
	l2.next = &node3;
	node3.next = &node4;

	ListNode l3(2);
	ListNode node5(6);
	l3.next = &node5;

	vector<ListNode*> lists{ &l1, &l2, &l3 };
	ListNode* res = mergeKLists1(lists);
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;

	system("pause");
	return 0;
}