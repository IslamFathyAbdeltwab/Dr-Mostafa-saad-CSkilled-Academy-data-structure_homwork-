#include <iostream>
#include <cassert>
#include <stack>
#include <algorithm>
using namespace std;
class Stack
{
private:
    int size{};
    int *arr{};
    int added_element{};

public:
    // problem 1
    Stack(int size) : size(size)
    {
        arr = new int[size];
    }
    bool IsFull()
    {
        return added_element == size;
    }
    bool IsEmpty()
    {
        return added_element == 0;
    }
    bool push(int val)
    {
        if (IsFull())
            return false;
        for (int i = added_element - 1; i >= 0; --i)
            arr[i + 1] = arr[i];
        arr[0] = val;
        ++added_element;
        return true;
    }
    bool pop(int &result)
    {
        if (IsEmpty())
            return false;
        result = arr[0];
        for (int i = 0; i < added_element - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        added_element--;
        return true;
    }
    int peek(int &result)
    {
        if (IsEmpty())
            return false;
        result = arr[0];
        return true;
    }
    void Display()
    {
        for (int i = 0; i < added_element; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
// o(n) time  o(n) memory problem 2
string reverse_word(string line)
{ // nbj j kl
    string output = "";
    stack<char> stack;
    for (int i = 0; i <= line.length(); i++)
    {
        if (line[i] != ' ' && line[i] != '\0')
        {
            stack.push(line[i]);
        }
        else if (line[i] == ' ' || line[i] == '\0')
        {
            while (!stack.empty())
            {
                output += stack.top();
                stack.pop();
            }
            (line[i] == '\000') ? output : output += " ";
        }
    }
    return output;
}
// o(N) time o(n) memory  problem 3
int reverse_num(int num)
{
    string output = "";
    stack<char> stack;
    string num_to_str = to_string(num);
    int final_result;
    for (int i = 0; i <= num_to_str.length(); i++)
    {
        if (num_to_str[i] == '\0')
        {
            while (!stack.empty())
            {
                output += stack.top();
                stack.pop();
            }
            final_result = stoi(output);
            return final_result;
        }
        stack.push(num_to_str[i]);
    }
    return 0;
}
// utility
bool open_and_closed(char open_tag, char closed_tag)
{
    bool is_sib = false;
    if (open_tag == '(' && closed_tag == ')')
    {
        is_sib = true;
    }
    else if (open_tag == '{' && closed_tag == '}')
    {
        is_sib = true;
    }
    else if (open_tag == '[' && closed_tag == ']')
    {
        is_sib = true;
    }

    return is_sib;
}
char get_open_match(char ch)
{
    if (ch == ')')
        return '(';
    if (ch == ']')
        return '[';
    return '{';
}
// o(n) time o(n) memory  problem 4
bool isValid(string str)
{
    stack<char> stack;
    for (int i = 0; i <= str.length(); i++)
    {
        char ch = str[i];

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack.push(str[i]);
        }

        else
        {
            if (open_and_closed(stack.top(), str[i]))
            {
                stack.pop();
                if (stack.empty() && i == str.length() - 1)
                {
                    return true;
                }
            }
            else
                return false;
        }
    }
    return false;
}
// o(n) time o(n) memory  problem 5
string removeDuplicates(string S)
{
    stack<char> stack;
    for (size_t i = 0; i < S.length(); i++)
    {
        if (stack.empty() || S[i] != stack.top())
        {
            stack.push(S[i]);
        }
        else if (S[i] == stack.top())
        {
            stack.pop();
        }
    }
    string output = "";
    while (!stack.empty())
    {
        output += stack.top();
        stack.pop();
    }
    reverse(output.begin(), output.end());
    return output;
}

int main()
{
    Stack stk(3);
    stk.push(10);
    stk.push(20);
    stk.push(30);
    if (!stk.push(50))
        cout << "Full Stack\n";
    stk.Display(); // 30 20 10
    int result;
    if (stk.peek(result))
        cout << "\n"
             << result << "\n"; // 30
    while (stk.pop(result))
    {
        cout << result << " ";
    }
    cout << endl;                                  // 30 20 10
    cout << reverse_word("abc d efg xy") << "\n";  // cba d gfe yx
    cout << reverse_num(1234) << "\n";             // 4321
    cout << isValid("(())") << "\n";               // 1
    cout << isValid("(()[()])") << "\n";           // 1
    cout << isValid("(][)") << "\n";               // 0
    cout << isValid("(()") << "\n";                // 0
    cout << isValid("()(") << "\n";                // 0
    cout << removeDuplicates("abbaca") << "\n";    // ca
    cout << removeDuplicates("abbacaac") << "\n";  // Empty
    cout << removeDuplicates("aabacaacd") << "\n"; // bad
    cout << removeDuplicates("abcddcba") << "\n";  // Empty
}
