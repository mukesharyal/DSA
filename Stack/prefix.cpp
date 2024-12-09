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

int assignValue(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
            break;

        case '*':
        case '/':
            return 2;
            break;

        default:
            return 0;
            break;
    }
}

string convertToPostfix(string expression)
{
    Stack stack;

    string result = "";

    int length = expression.length();

    for(int i = 0; i < length; i++)
    {
        char token = expression[i];

        switch(token)
        {
            case '(': // If the token is an opening parenthesis, just push it onto the stack
                stack.push(token);
                break;



            case ')': // If the token is a closing parenthesis, pop each operator from the stack and add them to the result till the opening 
                      // parenthesis is reached. And, pop the opening parenthesis from the stack.

                while(stack.seek() != '(')
                {
                    char topCharacter = stack.seek();

                    result += topCharacter;

                    stack.pop();
                }

                stack.pop();

                break;




            case '+':
            case '-':
            case '*':
            case '/': // There are a couple of things we need to be mindful of in this case

                while(!stack.isEmpty())
                {
                    if(stack.seek() == '(') // If the top of the stack is an opening parenthesis, we don't need to do anything
                    {
                        break;
                    }
                    else
                    {
                        if(assignValue(stack.seek() >= assignValue(token))) // If the precedence of the top of the stack is greater or equal
                                                                            // to the scanned character, pop it from the stack and add onto
                                                                            // the result
                        {
                            result += stack.seek();

                            stack.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                stack.push(token); // We always need to do this at the end

                break;


            default: // If the token is a number or a variable, just add it to the result
                result += token;
                break;

        }
    }

    // When all the tokens are scanned through, add the tokens remaining on the stack onto the result one by one

    while(!stack.isEmpty())
    {
        result += stack.seek();

        stack.pop();
    }

    return result;
}

string reverseString(string expression)
{
    int length = expression.length();

    string reversedString = "";

    for(int i = (length - 1); i >= 0; i--)
    {
        reversedString += expression[i];
    }

    return reversedString;
}




string convertToPrefix(string expression)
{
    // The procedure to convert an infix expression to a prefix expression is as follows:

    // 1. Reverse the given infix expression
    // 2. Replace ( by ) and vice versa
    // 3. Convert to postfix expression
    // 4. Finally, reverse it again to obtain the final result

    string result;

    result = reverseString(expression); // 1. Reverse the expression

    cout << "The reversed expression looks like: " << result << endl;

    int length = result.length();

    for(int i = 0; i < length; i++)
    {
        if(result[i] == '(')
        {
            result[i] = ')';
        }                               // 2. Replace ( by ) and vice versa
        else if(result[i] == ')')
        {
            result[i] = '(';
        }
    }

    result = convertToPostfix(result);  // 3. Convert to postfix

    result = reverseString(result);     // 4. Reverse it again

    
    return result;
}


int main()
{
    string infix, prefix;

    cout << "Enter the infix expression: ";
    cin >> infix;

    prefix = convertToPrefix(infix);

    cout << "The prefix expression is: " << prefix << endl;

    return 0;
}