#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<string> stack;

    stack.push("Hello");
    cout << "Hello had been add" << endl;
    stack.push("World");
    cout << "World had been add" << endl;
    stack.push("C++");
    cout << "C++ had been add" << endl;

    cout << "Top element: " << stack.top() << endl;

    if (stack.empty() == true)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    while (stack.empty() == false)
    {
        cout << "Top element: " << stack.top() << endl;
        stack.pop();
    }
    return 0;
}