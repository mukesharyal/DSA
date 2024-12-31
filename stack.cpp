#include <iostream>

using namespace std;

struct Node
{
    int data;

    Node* next;
};

class Stack
{
    private:

        Node* top = nullptr;

    public:

        void push(int val)
        {
            Node* node = new Node;

            node->data = val;

            if(top == nullptr)
            {
                top = node;

                node->next = nullptr;
            }
            else
            {
                Node* previousTop = top;

                top -> next = node;

                top = node;

                node->next = previousTop;
            }
        }



        void pop()
        {
            if(top == nullptr)
            {
                cout << "The stack is empty." << endl;

                return;
            }

            Node* previousTop = top->next;

            delete top;

            top = previousTop;
        }



        bool isEmpty()
        {
            return (top == nullptr);
        }



        int peek()
        {
            return top -> data;
        }




};


int main()
{
    Stack myStack;

    myStack.push(23);

    cout << myStack.peek() << endl;

    myStack.push(34);

    cout << myStack.peek() << endl;

    myStack.pop();

    cout << myStack.peek() << endl;

    return 0;
}
