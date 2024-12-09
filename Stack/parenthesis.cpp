#include <iostream>
#include <string>

using namespace std;

class Stack
{
	private:
		char arr[10];
		int top = -1;
		
	public:
	
		void push(char val)
		{
			if(top == 4)
			{
				cout << "The stack is full." << endl;
			}
			else
			{
				top = top + 1;
				
				arr[top] = val;
				
			}
		}
		
		void pop()
		{
			if(top == -1)
			{
				cout << "The stack is empty." << endl;
			}
			else
			{
				top = top - 1;
			}
		}
		
		char seek()
		{
			return arr[top];
		}

        bool isEmpty()
        {
            if(top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

bool checkParentheses(string expression)
{
    Stack stack;

    int length = expression.length();

    for(int i = 0; i < length; i++)
    {
        if(expression[i] == '(')
        {
            stack.push('(');
        }
        
        if(expression[i] == ')')
        {
            if(stack.isEmpty())
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }

    }

    if(stack.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    string expression;

    cout << "Enter the expression to be checked: ";
    cin >> expression;

    bool isValid = checkParentheses(expression);

    if(isValid)
    {
        cout << "The expression is valid." << endl;
    }
    else
    {
        cout << "The expression is invalid." << endl;
    }

    return 0;
}