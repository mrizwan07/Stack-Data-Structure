# Stack Functions

This repository contains a C++ class named `Stack` that implements a stack data structure along with various functions for stack manipulation and operations.

## Stack Class Functions

1. **Constructor:**
   - Initializes the stack with a specified size. Default size is 10.

2. **push:**
   - Pushes an element onto the top of the stack.

3. **pop:**
   - Pops the top element from the stack.

4. **topIndex:**
   - Returns the index of the top element in the stack.

5. **topValue:**
   - Returns the value of the top element in the stack.

6. **isEmpty:**
   - Checks if the stack is empty.

7. **isFull:**
   - Checks if the stack is full.

8. **reSize:**
   - Resizes the stack if it becomes full.

9. **balance:**
   - Checks if parentheses in a string are balanced.

10. **inFIXToPostFix:**
    - Converts an infix expression to a postfix expression.

11. **longestValidParentheses:**
    - Finds the length of the longest valid parentheses substring in a string.

12. **nextGreaterElement:**
    - Finds the next greater element for each element in an array.

13. **display:**
    - Displays the elements of the stack.

14. **preTopValue:**
    - Returns the value below the top element of the stack.

## Example Usage

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Example usage of Stack class functions
    Stack<int> s(3);
    s.push(12);
    s.push(20);
    s.push(14);
    s.push(15);
    s.push(30);
    s.push(31);
    s.push(3);
    s.display();

    // Balance parentheses check
    Stack<char> s1(20);
    if (s1.balance("[[[(a-b)]]]"))
    {
        cout << "Parentheses are balanced" << endl;
    }
    else
    {
        cout << "Parentheses are not balanced" << endl;
    }

    // Longest valid parentheses check
    cout << "Longest valid parentheses: " << longestValidParentheses("(((())((()") << endl;

    // Next greater element
    int arr[5] = {4, 5, 2, 25};
    int* arr1 = nextGreaterElement(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << "The next element of " << arr[i] << " is " << arr1[i] << endl;
    }
    delete[] arr1; 

    // Infix to Postfix conversion
    Stack<char> s3(20);
    string s4 = s3.inFIXToPostFix("a+b-c*d");
    cout << "Infix to Postfix: " << s4 << endl;

    // Removing duplicates from string
    cout << "String after removing duplicates: " << duplicate("aaabbccd") << endl;

    return 0;
}
