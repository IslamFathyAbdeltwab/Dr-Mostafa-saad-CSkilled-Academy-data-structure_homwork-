#include <iostream>
#include <cassert>
using namespace std;
// problem one
class Queue
{
private:
    int size{};
    int front{0};
    int rear{0};
    int *arr{};
    int added_element{};

public:
    Queue(int size) : size(size)
    {
        arr = new int[size];
    }
    int next(int ind)
    {
        if (ind == size - 1)
            return 0;
        return ind + 1;
    }
    int prv(int ind)
    {
        if (ind == 0)
            return size - 1;
        return ind - 1;
    }
    void Enqueue(int val)
    {
        assert(!IsFull());
        arr[rear] = val;
        rear = next(rear);
        added_element++;
    }
    int Dequeue()
    {
        int cur = arr[front];
        assert(!IsEmpty());
        front = next(front);
        added_element--;
        return cur;
    }
    //******* */
    void enqueue_rear(int value) 
    {
        Enqueue(value);
    }
    void enqueue_front(int value)
    {
        assert(!IsFull());
        front = prv(front);
        arr[front] = value;

        added_element++;
    }
    //********* */
    int dequeue_rear()
    {

        int cur = arr[prv(rear)];
        rear = prv(rear);
        added_element--;
        return cur;
    }
    int dequeue_front()
    {
        return Dequeue();
    }
    //****** */
    bool IsEmpty()
    {
        return added_element == 0;
    }
    bool IsFull()
    {
        return added_element == size;
    }
    void Display()
    {
        if (IsEmpty())
        {
            cout << "queue is empty!\n";
            return;
        }

        for (size_t i = front, cont = 0; cont < added_element; cont++)
        {
            cout << arr[i] << " ";
            i = next(i);
        }
    }
    int Front()
    {
        return arr[front];
    }
    int Back()
    {
        return arr[rear - 1];
    }
};

// problem two stack by queue
class Stack
{
private:
    Queue q;
    int added_element{0};
    void insert_front(int val)
    {
        int size = added_element;
        q.Enqueue(val);
        while (size--)
        {
            q.Enqueue(q.Dequeue());
        }
        added_element++;
    }

public:
    Stack(int size) : q(size) {}
    void push(int val)
    {
        insert_front(val);
    }
    int pop()
    {
        added_element--;
        return q.Dequeue();
    }
    int peek()
    {
        return q.Front();
    }

    int isFull()
    {
        return q.IsFull();
    }

    int isEmpty()
    {
        return q.IsEmpty();
    }
};

int main()
{
    //   //test problem two
    // Stack stk(3);
    // stk.push(10);
    // stk.push(20);
    // stk.push(30);

    // while (!stk.isEmpty())
    // {
    //     cout << stk.peek() << " ";
    //     stk.pop();
    // } // 30 20 10

    //test problem one
    Queue dq(6);
    dq.enqueue_front(3);
    dq.Display();
    dq.enqueue_front(2);
    dq.enqueue_rear(4);
    dq.enqueue_front(1);
    dq.enqueue_front(5);
    dq.enqueue_front(6);
    dq.Display(); // 6 5 1 2 3 4
    cout << endl;
    cout << dq.dequeue_rear() << "\n"; // 4
    dq.Display();                      // 6 5 1 2 3
    cout << endl;

    cout << dq.dequeue_front() << "\n"; // 6
    dq.Display();                       // 5 1 2 3
    cout << endl;
    cout << dq.dequeue_rear() << "\n";  // 3
    cout << dq.dequeue_front() << "\n"; // 5

    while (!dq.IsEmpty())
        dq.dequeue_rear();
    dq.Display(); // empty
    for (int i = 0; i < 6; ++i)
        dq.enqueue_rear(i + 10);
    dq.Display(); // 10 11 12 13 14 15
}