/*
���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㣬�㽫ֻ������Ҫ��ɾ���Ľڵ㡣

����һ������ --?head =?[4,5,1,9]�������Ա�ʾΪ:

ʾ�� 1:

����: head = [4,5,1,9], node = 5
���: [4,1,9]
����: ������������ֵΪ?5?�ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
ʾ�� 2:

����: head = [4,5,1,9], node = 1
���: [4,5,9]
����: ������������ֵΪ?1?�ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.
 ?

˵��:

�������ٰ��������ڵ㡣
���������нڵ��ֵ����Ψһ�ġ�
�����Ľڵ�Ϊ��ĩβ�ڵ㲢��һ���������е�һ����Ч�ڵ㡣
��Ҫ����ĺ����з����κν����
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node)
{
	node->val = node->next->val;
	node->next = node->next->next;
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
	cur = head->next;
	cin >> n;
	while (cur)
	{
		if (cur->val == n)
			break;
		cur = cur->next;
	}
	deleteNode(cur);
	ListNode* temp = head->next;
	while (temp)
	{
		cout << temp->val << ' ';
		temp = temp->next;
	}
	cout << endl;

	system("pause");
	return 0;
}