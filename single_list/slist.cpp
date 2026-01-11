#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int data) : data(data)
    {
    }
};
class single_list
{
public:
    int length = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    void Display()
    {
        if (!head)
        {
            cout << "the list is empty\n";
        }
        else
        {
            for (Node *cur = head; cur; cur = cur->next)
            {
                cout << cur->data << " ";
            }
        }
    }
    void DiRec(Node *head)
    {
        if (!head)
            return;
        cout << head->data << " ";
        DiRec(head->next);
    }
    void DiRecRevers(Node *head)
    {
        if (!head)
            return;
        DiRecRevers(head->next);
        cout << head->data << " ";
    }
    Node *find(int value)
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            if (cur->data == value)
            {
                return cur;
            }
        }
        return nullptr;
    }
    Node *get_nth(int n)
    {
        // if (n>length||n<1)
        // {
        //     return nullptr;
        // }
        // else if (n==length)
        // {
        //     return tail;
        // }
        // else{
        //     Node* cur=head;
        //     while (--n)
        //     {
        //        cur=cur->next;
        //     }
        //     return cur;
        // }

        int count = 0;
        for (Node *cur = head; cur; cur = cur->next)
        {
            if (++count == n)
            {
                return cur;
            }
        }

        return nullptr;
    }
    void insertFront(int valu)
    {

        Node *newnode = new Node(valu);
        if (!head)
        {
            head = newnode;
            newnode->next = nullptr;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        length++;
    }
    void insertIndx(int ind, int val)
    {
        if (ind < 0 || ind > length)
        {
            cout << "not index validn\n";
            return;
        }
        else
        {

            if (ind == 0)
            {
                insertFront(val);
            }
            else
            {
                Node *newnode = new Node(val);
                int index = 0;
                for (Node *cur = head; cur; cur = cur->next, index++)
                {
                    if (index == ind - 1)
                    {
                        newnode->next = cur->next;
                        cur->next = newnode;
                        break;
                    }
                }
                length++;
            }
        }
    }
    void insert_end(int val)
    {
        Node *newnode = new Node(val);
        if (!head)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        length++;
    }
    void deleteFirst()
    {
        if (!head)
        {
            cout << "not vaild deletion\n";
        }
        else if (length == 1)
        {
            tail = head = nullptr;
            length--;
        }
        else
        {
            Node *cur = head;
            head = head->next;
            delete cur;
            length--;
        }
    }
    void delet_nth(int ind)
    {
        if (ind == 1)
        {
            deleteFirst();
        }
        else if (ind == 0)
            cout << "error\n";
        else
        {
            int indx = 1;
            Node *prv = nullptr;
            for (Node *cur = head; cur; prv = cur, cur = cur->next, indx++)
            {
                if (ind == indx)
                {
                    prv->next = cur->next;
                    delete cur;
                    length--;
                    break;
                }
            }
        }
    }
    void deletLast()
    {
        if (length <= 1)
        {
            deleteFirst();
        }
        else
        {

            for (Node *cur = head; cur; cur = cur->next)
            {
                if (cur->next->next == nullptr)
                {
                    delete tail;
                    tail = cur;
                    tail->next = nullptr;
                }
            }
        }
    }
    bool is_same(const single_list &other)
    {
        // if (length!=other.length)
        // {
        //     return false;
        // }
        // else
        // {&&
        Node *cur_other = other.head;
        Node *cur = head;
        if (!cur_other && cur || cur_other && !cur)
        {
            return false;
        }
        else
        {
            for (; cur || cur_other; cur = cur->next, cur_other = cur_other->next)
            {
                if (cur->data != cur_other->data)
                    return false;
            }
        }

        // }
        return true;
    }
    Node *get_tail()
    {

        for (Node *cur = head; cur; cur = cur->next)
        {
            if (!cur->next)
            {
                return cur;
            }
        }
        return nullptr;
    }
    void swap_pairs()
    {
        Node *prv = head;
        for (Node *cur = head->next; cur; prv = cur->next, cur = prv->next)
        {
            swap(prv->data, cur->data);
            if (!cur->next)
            {
                break;
            }
        }
    }
    void reverse()
    {
        tail = head;
        Node *prv = head;
        Node *cur = head->next;
        while (cur)
        {
            Node *save_next = cur->next;

            cur->next = prv;

            prv = cur;
            cur = save_next;
        }
        head = prv;
        tail->next = nullptr;
    }
    void delete_even_positions()
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            Node *to_deleet = cur->next;

            if (cur->next == nullptr)
            {
                break;
            }

            // bool is_tail=to_deleet==t;

            else if (to_deleet->next == nullptr)
            {
                // cout<<is_tail;
                cur->next = nullptr;
                delete to_deleet;
                length--;
                tail = cur;
            }
            else
            {
                // cout<<is_tail;
                cur->next = to_deleet->next;
                delete to_deleet;
                length--;
                // Display();
                // cout<<endl;
            }
        }
    }
    void insert_sorted(int value)
    {
        if (length == 0 || length == 1 || head->data >= value)
        {
            insertFront(value);
            return;
        }

        else
        {
            Node *newnode = new Node(value);
            Node *prv = nullptr;
            for (Node *cur = head; cur; prv = cur, cur = cur->next)
            {
                if (cur->data >= value)
                {
                    newnode->next = cur;
                    prv->next = newnode;
                    length++;
                    return;
                }
            }
            insert_end(value);
        }
    }
    Node *get_previous(Node *target)
    {
        for (Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
        {
            if (cur == target)
                return prv;
        }
        return nullptr;
    }
    void left_rotate(int k)
    {
        k %= length;
        if (k == 0)
        {
            return;
        }

        for (int i = 1; i <= k; i++)
        {
            Node *prv = get_previous(tail);
            tail->next = head;
            head = tail;
            tail = prv;
            prv->next = nullptr;
        }
    }
    void Remove_duplicates() // o(n) time  o(1) memory
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            Node *prv = cur;
            for (Node *loopping = cur->next; loopping; prv = loopping, loopping = loopping->next)
            {
                if (cur->data == loopping->data)
                {
                    if (loopping->next == nullptr)
                    {
                        delete loopping;
                        tail = prv;
                        tail->next = nullptr;
                        break;
                    }
                    prv->next = loopping->next;
                    delete loopping;
                    loopping = prv;
                }
            }
        }
    }
    void Swap_head_and_tail()
    {
        if (!head || length == 1)
        {
            cout << "operation is not vaild\n";
            return;
        }
        else if (length == 2)
        {
            swap(tail, head);
            tail->next = head;
            head->next = nullptr;
        }
        else
        {

            Node *prv_tail = nullptr;
            for (Node *cur = head; cur; cur = cur->next)
            {
                if (cur->next->next == nullptr)
                {
                    prv_tail = cur;
                    break;
                }
            }
            tail->next = head->next;
            prv_tail->next = head;
            head->next = nullptr;
            swap(tail, head);
        }
    }
    void Remove_last_occurance(int key)
    {
        if (head->data == key && length == 1)
        {
            head = tail = nullptr;
            length--;
        }
        else
        {
            Node *catched = nullptr;
            bool founded = false;
            Node *prv = nullptr;
            Node *save_prv = nullptr;
            for (Node *cur = head; cur; prv = cur, cur = cur->next)
            {
                if (cur->data == key)
                {
                    catched = cur;
                    save_prv = prv;
                    founded = true;
                }
            }
            if (founded)
            {
                if (!save_prv)
                {
                    Node *cur = head; // if founded and it a head
                    head = head->next;
                    delete cur;
                    length--;
                }
                else if (!catched->next)
                {
                    delete catched;
                    tail = save_prv;
                    tail->next = nullptr; // if founded and it a tail
                    length--;
                }
                else
                {
                    save_prv->next = catched->next;
                    delete catched; // if founded and it a middel
                    length--;
                }
            }
        }
    }
    void Move_to_back(int key)
    {
        Node *prv = nullptr;
        Node *cur = head;
        int i = length;
        while (i--)
        {
            if (cur->data == key)
            {
                if (!prv)
                {
                    insert_end(key);
                    deleteFirst();       //if ahead is a target
                    cur = prv;
                }
                else
                {
                    prv->next = cur->next;
                    delete cur;
                    cur = prv;
                    insert_end(key);
                }
            }

            if (!cur)      // if ahead is atarget you must keep cur point to the head to keep loop work
            {
                prv = cur;
                cur = head;       
            }
            else
            {
                prv = cur;
                cur = cur->next;
            }
        }
    }
    // int maxNum(Node* head){ 
    //     Node* cur=head;
    //     int max=0;
    //     if (!cur)
    //     {
    //         return  INT_MIN;
    //     }
    //     int save=maxNum(cur->next);
    //     if (max<cur->data)
    //     {
    //         max=cur->data;
    //     }
    //     else
    //     max=save;
    //     return max;
    // }
    int maxNum(Node* head) {   //o(n) time o(n) memory
    if (!head) {
        return 0; 
    }
    int max_so_far = head->data;  
    int max_in_rest = maxNum(head->next); 
    return (max_so_far > max_in_rest) ? max_so_far : max_in_rest; 
}
    ~single_list()
    {
        if (!head)
        {
            cout << "the list is empty \n";
        }
        else
        {

            while (head)
            {
                Node *cur = head->next;
                delete head;
                head = cur;
            }
        }
        head = tail = nullptr;
    }
};
int main()
{
    single_list list;
    // s.DiRecRevers(head);
    // cout << s.is_same(d);
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    // list.insert_end(1);
    // list.insert_end(2);
    // list.insert_end(4);
    // list.insert_end(1);
    // list.insert_end(7);
    // list.insert_end(1);
    // list.insert_end(8);
    // list.insert_end(1);
    // list.insert_end(1);
    // list.Move_to_back(1);
    list.Display();
    cout<<endl;
    cout<< list.maxNum(list.head);
    // s.insert_end(10);
    // // s.insert_end(20);
    // // s.insert_end(10);
    // // s.insert_end(40);
    // // s.insert_end(20);
    // // s.insert_end(30);
    //  s.Display();
    // cout << endl;
    // s.Remove_last_occurance(10);
    // // s.insert_end(40);
    // s.insert_end(30);
    // s.insert_end(50);
    // s.insert_end(20);
    // s.insert_end(20);
    // s.insert_end(30);
    // s.insert_end(20);
    // s.left_rotate(1);
    // s.Remove_duplicates();
    // s.insert_end(80);
    // s.insert_end(8);
    // s.insertFront(5);
    // s.insert_sorted(40);
    // s.insert_end(1);
    // s.Swap_head_and_tail();
    // s.insert_end(2);
    // s.insert_end(3);
    // s.Swap_head_and_tail();
    // s.insert_end(4);
    // s.insert_end(5);
    // s.Swap_head_and_tail();
    // s.Display();
    // cout << endl;
    // s.delet_nth(2);
    // s.swap_pairs();
    // s.reverse();
    // s.delete_even_positions();
    // s.Display();
    // cout<<endl;
    // cout<< s.get_tail();
    // cout << endl;
    // cout << s.is_same(d);
    // cout << endl;
    // d.insert_end(20);
    // d.insert_end(30);
    // d.insertFront(5);
    // d.Display();
    // cout << endl;
    // cout << s.is_same(d);
    return 0;
}
