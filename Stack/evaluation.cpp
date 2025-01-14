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
                        if(assignValue(stack.seek()) >= assignValue(token)) // If the precedence of the top of the stack is greater or equal
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

int operate(char a, char b, char op)
{
    int result;

    int operandA = a - 48;

    int operandB = b - 48;

    switch(op)
    {
        case '+':
            result = operandA + operandB;
            break;
        
        case '-':
            result = operandA - operandB;
            break;

        case '*':
            result = operandA * operandB;
            break;

        case '/':
            result = operandA / operandB;
            break;

    }

    return result;
}




int evaluateExpression(string expression)
{
    Stack stack;

    // I will have a postfix expression by default. So, the expression will contain either a number or an operator

    int length = expression.length();

    int operandA, operandB, result;

    for(int i = 0; i < length; i++)
    {
        switch(expression[i]) 
        {
            case '+':
            case '-':
            case '*':
            case '/': // When we encounter an operator, operate the two operands on the top of the stack, and store the result on the stack

                operandB = stack.seek();
                stack.pop();

                operandA = stack.seek();
                stack.pop();

                result = operate(operandA, operandB, expression[i]);

                stack.push(result + 48);

                break;




            default: // When we encounter an operand, just push it onto the stack

                stack.push(expression[i]);
                break;
        }
    }

    return stack.seek();
}




int main()
{
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    expression = convertToPostfix(expression);

    int result = evaluateExpression(expression) - 48;

    cout << "The result is: " << result << endl;
}