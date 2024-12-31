#include <iostream>

using namespace std;

struct Node
{
    int data;

    Node* next;
};

class Queue
{
    private:

        Node* frontOfQueue = nullptr;

        Node* rearOfQueue = nullptr;



    public:

        void enqueue(int val)
        {
            Node* node = new Node;

            node->data = val;

            if(frontOfQueue == nullptr)
            {
                frontOfQueue = node;

            }
            else
            {
                 rearOfQueue->next = node;
            }

            rearOfQueue = node;
        }


        int dequeue()
        {
            if(frontOfQueue == nullptr)
            {
                cout << "The queue is empty." << endl;

                return -1;
            }

            if(frontOfQueue == rearOfQueue)
            {
                int value = frontOfQueue->data;

                delete frontOfQueue;

                frontOfQueue = nullptr;
                rearOfQueue = nullptr;

                return value;
            }
            else
            {
                int value = frontOfQueue->data;

                frontOfQueue = frontOfQueue->next;

                return value;
            }
        }

};


int main()
{
    Queue myQueue;

    myQueue.enqueue(23);
    myQueue.enqueue(25);

    cout << myQueue.dequeue() << endl;

    myQueue.enqueue(47);

    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;

    return 0;
}


