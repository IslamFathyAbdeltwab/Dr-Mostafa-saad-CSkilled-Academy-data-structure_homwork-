#include <iostream>
using namespace std;
class Vector
{
private:
    int size;
    int capacity;
    int *arr = nullptr;

public:
    Vector(int size) : size(size)
    {

        if (size < 1)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity]{};
    }
    void insert(int idex, int val)
    {
        if (size == capacity)
        {
            int *newarr = new int[size + 1];
            for (int i = 0; i < size; i++)
            {
                newarr[i] = arr[i];
                swap(arr, newarr);
                delete[] newarr;
            }
        }

        for (int i = size; i > idex; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[idex] = val;
        size++;
    }
    void bush_back(int val)
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *newarr = new int[capacity];
            for (size_t i = 0; i < size; i++)
            {
                newarr[i] = arr[i];
            }
            swap(arr, newarr);
            delete[] newarr;
        }
        arr[size++] = val;
    }
    void set(int index, int val)
    {
        if (index >= 0 && index < capacity)
            arr[index] = val;
    }
    int Get(int index)
    {
        if (index >= 0 && index < size)
            return arr[index];
    }
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
    int find(int val)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == val)
                return i;
        }
        return -1;
    }
    void right_rotat_tims(int time)
    {

        time %= size;

        if (!time)
        {
            return;
        }

        else
        {
            for (int i = 1; i <= time; i++)
            {
                right_rotat();
            }
        }
    }
    void right_rotat()
    {
        int end_val = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = end_val;
    }
    void left_rotat()
    {
        int first_val = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = first_val;
    }
    int pop(int index)
    {
        int deleted_value = arr[index];

        // int *arr2 = new int[size - 1];
        // for (int i = 0, j = 0; i < size, j < size - 1; j++, i++)
        // {
        //     if (i == index)
        //     {
        //         j = index - 1;
        //         continue;
        //     }
        //     arr2[j] = arr[i];
        // }
        // swap(arr, arr2);
        // delete[] arr2;

        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        --size;
        return deleted_value;
    }
    int GetFront()
    {
        return arr[0];
    }
    int Getback()
    {
        return arr[size - 1];
    }
    int find_transposition(int value)
    {

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                if (i == 0)
                {
                    return 0;
                }

                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
        return -1;
    }
    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }
};
int main()
{

    int n = 5;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);

    v.display();
    cout << endl; // 0 1 2 3 4
    v.right_rotat_tims(5 * 1000);
    v.display();
    cout << endl; // 0 1 2 3 4
    v.right_rotat_tims(2);
    v.display();
    cout << endl; // 3 4 0 1 2
    v.left_rotat();
    v.display();
    cout << endl; // 4 0 1 2 3
    int val = v.pop(2);
    cout << val << "\n"; // 1
    v.display();         // 4 0 2 3
    cout << endl;

    cout << v.find_transposition(3) << "\n"; // 2
    v.display();                             // 4 0 3 2

    return 0;
}
