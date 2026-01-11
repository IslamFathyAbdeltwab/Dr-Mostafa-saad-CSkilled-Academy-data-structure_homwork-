#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    Node *prv{};
    Node(int data) : data(data) {}
};
class DLL
{
public:
    Node *head{};
    Node *tail{};
    int length = 0;

public:
    void link(Node *first, Node *seconde)
    {
        if (first)
        {
            first->next = seconde;
        }
        if (seconde)
        {
            seconde->prv = first;
        }
    }
    void insert_end(int value)
    {
        Node *newnode = new Node(value);
        length++;
        if (!head)
        {
            head = tail = newnode;
        }
        else
        {
            link(tail, newnode);
            tail = newnode;
        }
    }
    void insert_front(int value)
    {
        Node *newnode = new Node(value);
        length++;
        if (!head)
        {
            head = tail = newnode;
        }
        else
        {
            link(newnode, head);
            head = newnode;
        }
    }
    void embed_after(Node *befour_target, int value)
    {
        Node *newnode = new Node(value);
        length++; // will creat newnode and connect the this node with the prvious and the next
        Node *next_target = befour_target->next;
        link(befour_target, newnode);
        link(newnode, next_target);
    }
    void insert_sorted(int value)
    {
        if (head->data >= value || !length)
        {
            insert_front(value);
        }
        else if (tail->data <= value)
        {
            insert_end(value);
        }
        else
        {
            for (Node *cur = head, *prvious = nullptr; cur; prvious = cur, cur = cur->next)
            {
                if (cur->data >= value)
                {
                    embed_after(cur->prv, value);
                    break;
                }
            }
        }
    }
    void delete_end()
    {
        if (!head)
        {
            return;
        }
        else
        {
            Node *cur = tail;
            tail = tail->prv;
            delete cur;
            length--;
            if (tail)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
        }
    }
    void delete_front()
    {
        if (!head)
        {
            return;
        }
        else
        {
            Node *cur = head;
            head = head->next;
            delete cur;
            length--;
            if (head)
            {
                head->prv = nullptr;
            }
            else
            {
                tail = nullptr;
            }
        }
        // else if (length == 1)
        // {
        //     delete head;
        //     head = tail = nullptr;
        //     length--;
        // }
        // else if (length==2)
        // {
        //     delete head;
        //     head=tail;
        //     head->prv=nullptr;

        // }
    }
    Node *delete_and_link(Node *cur)
    {
        Node *to_returned = cur->prv;
        link(cur->prv, cur->next);
        delete cur;
        return to_returned;
    }
    void delete_node_with_key(int key)
    {
        if (head->data == key)
        {
            delete_front();
            return;
        }

        for (Node *cur = head; cur; cur = cur->next)
        {
            if (cur->data == key)
            {
                cur = delete_and_link(cur);
                if (!cur->next)
                {
                    tail = cur;
                }

                break;
            }
        }
    }
    void delete_all_nodes_with_key(int value) // o(n)time  o(1)memory
    {
        if (length == 1 && head->data == value)
        {
            delete_front();
            return;
        }
        else
        {
            insert_front(-value); // insert dummy. assume -value no overflow
            for (Node *cur = head; cur;)
            {
                if (cur->data == value)
                {
                    cur = delete_and_link(cur);
                    if (!cur->next)
                        tail = cur;
                }
                else
                    cur = cur->next;
            }
            delete_front();
        }
    }
    void delete_even_positions()
    {
        for (Node *cur = head; cur && cur->next; cur = cur->next)
        {
            delete_and_link(cur->next);

            if (!cur->next)
            {
                tail = cur;
            }
        }
    }
     void delete_odd_positions()
     {
        insert_front(-5);
        // for (Node*cur=head;cur && cur->next;cur=cur->next)
        // {
        //    delete_and_link(cur->next);
        //    if (!cur->next)
        //    {
        //       tail=cur;
        //    }
           
        // }
        delete_even_positions();
        delete_front();
        
     }
     bool is_palindrome()
     {
        Node*front=head;
        Node*end=tail;
        int i=length/2;
        if (length==1)
        {
            return true;
        }
        else
        {
             while (--i)
        {
            if (front->data!=end->data)
            {
                return false;
            }
            
            front=front->next;
            end=end->prv;
            
        }
        return true;



        }
        

       
        

     }
     void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            cout << cur->data << " ";
        }
    }
};
int main()
{
    DLL d1;
    //   d1.insert_fron
    d1.insert_end(1);
    d1.insert_end(3);
    // d1.insert_end(2);
    d1.insert_end(1);
    // d1.insert_end(6);
    // d1.insert_end(6);
    // // d1.insert_end(6);
    // // d1.insert_end(6);
    // // d1.insert_sorted(5);
    // d1.print();
    // // d1.delete_all_nodes_with_key(5);
    // d1.delete_odd_positions();
    // cout << endl;
    // d1.print();

cout<<d1.is_palindrome();
    return 0;
}
