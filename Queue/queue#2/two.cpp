#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
	int size{};
	int top{};
	int *array{};

public:
	Stack(int size) : size(size), top(-1)
	{
		array = new int[size];
	}

	~Stack()
	{
		delete[] array;
	}

	void push(int x)
	{
		assert(!isFull());
		array[++top] = x;
	}
	void insert_at_bottom(int x)
	{
		// assert(!isFull());
		if (isEmpty())
		{
			push(x);
		}
		else
		{
			int cur = pop();
			insert_at_bottom(x);
			push(cur);
		}

		// for (int i = top; i >=0; --i)
		// {
		// 	array[i+1]=array[i];
		// }
		// top++;
		// array[0]=x;

		// need to arrive the end of the stack
		// add the value at the end
	}
	void reverse()
	{
		if (isEmpty())
		{
			return;
		}
		else
		{
			int cur = pop();
			reverse();
			insert_at_bottom(cur);
		}
	}

	int pop()
	{
		assert(!isEmpty());
		return array[top--];
	}

	int peek()
	{
		assert(!isEmpty());
		return array[top];
	}

	int isFull()
	{
		return top == size - 1;
	}

	int isEmpty()
	{
		return top == -1;
	}
	void display_reversed()
	{
		for (int i = 0; i <= top; i++)
			cout << array[i] << " ";
		cout << "\n";
	}

	void display()
	{
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}
};
// one
class queue
{
private:
	int size;
	int added_element{};
	Stack s1;
	Stack s2;

	void chanage_stackes(Stack &one, Stack &two)
	{
		// assert(!one.isEmpty() && two.isEmpty());
		while (!two.isEmpty())
		{
			one.push(two.pop());
		}
	}

public:
	queue(int size) : size(size), s1(size), s2(size)
	{
	}
	void enqueue(int data)
	{
		assert(!s1.isFull());
		chanage_stackes(s2, s1);
		s1.push(data);
		added_element++;
		chanage_stackes(s1, s2);
	}
	int dequeue()
	{
		assert(!isEmpty());
		int value = s1.pop();
		--added_element;
		return value;
	}
	// void display()
	// {
	// 	assert(!isEmpty());
	// 	chanage_stackes(s2,s1);
	// 	while (!isEmpty())
	// 	{
	// 		cout << s1.pop() << " ";
	// 	}

	// }
	int isEmpty()
	{
		return added_element == 0;
	}

	bool isFull()
	{
		return added_element == size;
	}
};
int main()
{
	queue qu(6);
	for (int i = 1; i <= 3; ++i)
		qu.enqueue(i);

	cout << qu.dequeue() << " ";

	for (int i = 4; i <= 5; ++i)
		qu.enqueue(i);

	while (!qu.isEmpty())
		cout << qu.dequeue() << " ";

	return 0;
}
