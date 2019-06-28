/*
���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

push(x)?-- ��Ԫ�� x ����ջ�С�
pop()?-- ɾ��ջ����Ԫ�ء�
top()?-- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�
ʾ��:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
	stack<int> s;
	stack<int> min;
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (min.empty() || x < min.top())
			min.push(x);
		s.push(x);
	}

	void pop() {
		if (min.top() == s.top())
			min.pop();
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min.top();
	}
};

int main()
{
	MinStack* minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	int min = minStack->getMin();
	cout << min << endl;
	minStack->pop();
	int top = minStack->top();
	cout << top << endl;
	min = minStack->getMin();
	cout << min << endl;

	system("pause");
	return 0;
}