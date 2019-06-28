/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x)?-- 将元素 x 推入栈中。
pop()?-- 删除栈顶的元素。
top()?-- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
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