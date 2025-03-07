#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> s;

    std::cout << "Initial stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack size after pushes: " << s.size() << std::endl;
    std::cout << "Stack top element: " << s.top() << std::endl;

    // Pop an element
    s.pop();
    std::cout << "Stack top after pop: " << s.top() << std::endl;
    std::cout << "Stack size after pop: " << s.size() << std::endl;

    // Pop all elements
    s.pop();
    s.pop();

    std::cout << "Stack empty after popping everything? " << (s.empty() ? "Yes" : "No") << std::endl;

    // Try popping from empty stack
    try 
    {
        s.pop();
    } 
    catch (const std::underflow_error& e) 
    {
        std::cout << "Exception caught on pop(): " << e.what() << std::endl;
    }

    // Try accessing top from empty stack
    try 
    {
        s.top();
    } 
    catch (const std::underflow_error& e) 
    {
        std::cout << "Exception caught on top(): " << e.what() << std::endl;
    }
    return 0;
}
