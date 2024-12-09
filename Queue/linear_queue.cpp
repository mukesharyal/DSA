#include <iostream>

using namespace std;

class LinearQueue
{
    private:
        int arr[7];

        int rear = -1;
        int front = -1;

    public:

        void enqueue(int val) 
        {
            if(rear == 6) // If the queue is full
            {
                cout << "The queue is full." << endl;
                return;
            }

            if(front == -1) // If the queue is empty
            {
                front = 0;
            }

            rear = rear + 1;

            arr[rear] = val;

            
        }


        void dequeue()
        {
            if(front == -1)
            {
                cout << "The queue is empty." << endl;
                return;
            }

            if(front == rear)
            {
                front = -1;
                rear = -1;
                return;
            }

            front = front + 1;

        }
};

int main()
{
    LinearQueue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    

    return 0;
}