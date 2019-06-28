/*
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

���������������



�ڽڵ� c1 ��ʼ�ཻ��

?

ʾ�� 1��

���룺intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
�����Reference of the node with value = 8
������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ [4,1,8,4,5]������ B Ϊ [5,0,1,8,4,5]���� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣
 ?

ʾ��?2��

���룺intersectVal?= 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
�����Reference of the node with value = 2
������ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ [0,9,1,2,4]������ B Ϊ [3,2,4]���� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣
  ?

ʾ��?3��

���룺intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
�����null
������ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ [2,6,4]������ B Ϊ [1,5]�����������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
���ͣ������������ཻ����˷��� null��
   ?
ע�⣺

�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//ʹ������ȳ���Ȼ��һ�������ָ����ȷ���
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (!headA || !headB)
		return NULL;
	int lenA = 0;
	int lenB = 0;
	ListNode* curA = headA;
	ListNode* curB = headB;
	while (curA)
	{
		lenA++;
		curA = curA->next;
	}
	while (curB)
	{
		lenB++;
		curB = curB->next;
	}
	int minLen = lenA <= lenB ? lenA : lenB;
	int moveLen = lenA <= lenB ? (lenB - lenA) : (lenA - lenB);
	curA = headA;
	curB = headB;
	if (lenA < lenB)
	{
		while (moveLen)
		{
			curB = curB->next;
			moveLen--;
		}
	}
	else
	{
		while (moveLen)
		{
			curA = curA->next;
			moveLen--;
		}
	}
	while (curA && curB && curA != curB)
	{
		curA = curA->next;
		curB = curB->next;
	}
	return curA;
}

int main()
{
	ListNode* headA = new ListNode(0);
	ListNode* curA = headA;
	int n;
	while (cin >> n)
	{
		curA->next = new ListNode(n);
		curA = curA->next;
		if (cin.get() == '\n')
			break;
	}
	curA = headA->next;
	ListNode* headB = new ListNode(0);
	ListNode* curB = headB;
	while (cin >> n)
	{
		curB->next = new ListNode(n);
		curB = curB->next;
		if (cin.get() == '\n')
			break;
	}
	cin >> n;
	while (curA && n)
	{
		curA = curA->next;
		n--;
	}
	curB->next = curA;
	ListNode* res = getIntersectionNode(headA->next, headB->next);
	cout << res->val << endl;

	system("pause");
	return 0;
}