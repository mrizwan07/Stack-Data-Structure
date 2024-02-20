#include <iostream>
using namespace std;
template <typename T>
class Stack
{
	T* stack;
	int size;
	int top;
public:
	Stack(int s =10)
	{
		size = s;
		stack = new T[size];
		top = -1;
	}
	~Stack()
	{
		if (stack)
		{
			delete[] stack;
			stack = nullptr;
		}
	}
	void push(T val)
	{
		if(isFull())
		{
			reSize();
		}
		stack[++top] = val;
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty";
		}
		else
		{
			--top;
		}
	}
	int topIndex()
	{
		return top;
	}
	T topValue()
	{
		return stack[top];
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (top == size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void reSize()
	{
		T* temp = new T[size * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = stack[i];
		}
		delete[] stack;
		stack = temp;
		size = size * 2;
	}

	int strlength(const char* s)
	{
		int i = 0, count = 0;
		while (s[i] != '\0') 
		{
			count++;
			i++; 
		}
		return count;
	}

	bool balance(const char* s)
	{
		int stringSize = strlen(s);
		for (int i = 0; i < stringSize; i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				push(s[i]);
			}
			else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
				if (isEmpty() || (s[i] == ')' && stack[top] != '(') || (s[i] == '}' && stack[top] != '{') || (s[i] == ']' && stack[top] != '['))
				{
					return false;
				}
				pop();
			}
		}
		return isEmpty();
	}


	int precedence(char op)
	{
		if (op == '+' || op == '-')
			return 1;
		else if (op == '*' || op == '/')
			return 2;
		else
			return 0;
	}

	string inFIXToPostFix(const char* s)
	{
		string postfix;
		int stringSize = strlen(s);
		for (int i = 0; i < stringSize; i++)
		{
			if (s[i] == '(')
			{
				push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!isEmpty() && stack[top] != '(')
				{
					postfix += stack[top];
					pop();
				}
				pop();
			}
			else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			{
				while (!isEmpty() && precedence(s[i]) <= precedence(stack[top]))
				{
					postfix += stack[top];
					pop();
				}
				push(s[i]);
			}
			else 
			{
				postfix += s[i];
			}
		}
		while (!isEmpty())
		{
			postfix += stack[top];
			pop();
		}
		return postfix;
	}


	int longestValidParentheses(const char* s)
	{
		int count = 0;
		int stringSize = strlen(s);
		for (int i = 0; i < stringSize; i++)
		{
			if (s[i] == '(')
			{
				push(s[i]);
			}
			if (s[i] == ')' && stack[top] == '(')
			{
				pop();
				count++;
			}
		}
		return count * 2;
	}
	void nextGreaterElement(int *s)
	{
		int stringSize = strlen(s);


	}

	void display()
	{
		for (int  i = 0; i <= top; i++)
		{
			cout<< stack[i]<< endl;

		}
	}
	T preTopValue()
	{
		return stack[--top];
	}
};

int longestValidParentheses(const char* s)
{
	Stack<char> sta;
	int count = 0;
	int stringSize = strlen(s);
	for (int i = 0; i < stringSize; i++)
	{
		if (s[i] == '(')
		{
			sta.push(s[i]);
		}
		if (s[i] == ')' && sta.topValue() == '(')
		{
			sta.pop();
			count++;
		}
	}
	return count * 2;
}
int * nextGreaterElement(int arr[], int size)
{
	int count = 0;
	int temp[6];
	Stack <int> sta;
	for (int  i = 0; i < size; i++)
	{
		sta.push(arr[i]);
		for (int j = 0; j < size; j++)
		{
			if (sta.topValue() > arr[j])
			{
				sta.pop();
				sta.push(arr[i]);

			}
		}
		temp[i] = sta.topValue();
	}
	return temp;
}
string duplicate(const char* s)
{
	string result;
	Stack<char> sta;
	int size = strlen(s);
	for (int i = 0; i < size; i++)
	{
		if (sta.isEmpty() || sta.topValue() != s[i])
		{
			sta.push(s[i]);
			result += s[i];
		}
		else
		{
			sta.pop();
		}
	}
	return result;
}


int main()
{
	Stack<int> s(3);
	s.push(12);
	s.push(20);
	s.push(14);
	s.push(15);
	s.push(30);
	s.push(31);
	s.push(3);
	s.display();
	cout << "------------------------------------------------------" << endl;
	s.pop();
	s.display();
	s.pop();
	s.display();

	Stack<char> s1(20);
	if (s1.balance("[[[(a-b)]]]"))
	{
		cout << "Parentheses are balanced" << endl;
	}
	else
	{
		cout << "Parentheses are not balanced" << endl;
	}

	cout << "Longest valid parentheses: " << longestValidParentheses("(((())((()") << endl;

	int arr[5] = { 4, 5, 2, 25 };
	int* arr1 = nextGreaterElement(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << "The next element of " << arr[i] << " is " << arr1[i] << endl;
	}
	delete[] arr1; 

	Stack<char> s3(20);
	string s4 = s3.inFIXToPostFix("a+b-c*d");
	cout << "Infix to Postfix: " << s4 << endl;

	cout << "String after removing duplicates: " << duplicate("aaabbccd") << endl;

	return 0;
}
