#include <iostream>

using namespace std;

class Stack
{
	private:
		int arr[5];
		int top = -1;
		
	public:
	
		void push(int val)
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
		
		int seek()
		{
			return arr[top];
		}
};


int main()
{
	Stack stack;
	
	stack.push(10);
	stack.push(12);
	stack.push(14);
	stack.push(16);
	stack.push(18);
	stack.push(20);
	
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
}
