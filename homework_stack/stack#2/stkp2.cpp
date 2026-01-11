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

	// problem two
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
	// problem three
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
// problem one
void asteroidCollision(int arr[], int len)
{
	Stack s(len);
	for (int i = 0; i < len; i++)
	{
		bool explode = false;
		while (!s.isEmpty() && arr[i] < 0 && s.peek() >= 0)
		{
			if (s.peek() < -arr[i])
			{
				s.pop();
				continue;
			}
			else if (s.peek() == -arr[i])
			{
				s.pop();
			}
			explode = true;
			break;
		}

		if (!explode)
		{
			s.push(arr[i]);
		}
	}
	s.display_reversed();
}
//problem four
void next_greater_num(int v[], int len)
{
	Stack s1(len);
	for (size_t i = 0; i < len; i++)
	{
		while (!s1.isEmpty() && v[i] > v[s1.peek()])
		{
			v[s1.pop()] = v[i];
		}
		s1.push(i);
	}
	while (!s1.isEmpty())
	{
		v[s1.pop()] = -1;
	}
	for (size_t i = 0; i < len; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	// test one
	int arr[] = {1, 0, -1, 1};
	asteroidCollision(arr, 4);
	// test two
	Stack stk(10);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.display();	// 3 2 1
	cout << "efter insert buttm\n";
	stk.insert_at_bottom(7);
	stk.display();	// 3 2 1 7
	// test three
	Stack stk2(10);
	stk2.push(1);
	stk2.push(2);
	stk2.push(3);
	stk2.display();	// 3 2 1
	cout << "after reverse\n";
	stk2.reverse();
	stk2.display();	// 1 2 3
 	// test four
	const int LEN1 = 8;
	int v1[LEN1]{73, 74, 75, 71, 69, 72, 76, 73};
	next_greater_num(v1, LEN1);
	const int LEN2 = 13;
	int v2[LEN2]{20, 10, 7, 8, 9, 15, 14, 13, 12, 13, 14, 15, 16};
	next_greater_num(v2, LEN2);

	return 0;
}
