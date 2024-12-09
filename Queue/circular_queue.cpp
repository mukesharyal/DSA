#include <iostream>

using namespace std;

class CircularQueue
{
    private:
        int arr[7];

        int front = -1;
        int rear = -1;

    public:

        void enqueue(int val)
        {
            if((rear + 1) % 7 == front) // If the queue is full
            {
                cout << "The queue is full." << endl;
                return;
            }

            if(front == -1) // If the queue is empty
            {
                front = 0;
            }

            rear = (rear + 1) % 7;

            arr[rear] = val;

        }


        void dequeue()
        {
            if(front == -1) // If the queue is empty
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

            front = (front + 1) % 7;
        }


        void show()
        {
            cout << "Showing the queue: " << endl;

            for(int i = 0; i < 7; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            for(int i = 0; i < 7; i++)
            {
                if(i == front || i == rear)
                {
                    cout << "^ ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;

            for(int i = 0; i < 7; i++)
            {
                if(i == front || i == rear)
                {
                    cout << "| ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;

            for(int i = 0; i < 7; i++)
            {
                if(i == front)
                {
                    cout << "F ";
                }
                else if(i == rear)
                {
                    cout << "R ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
};


int main()
{
    CircularQueue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);

    queue.show();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();


    queue.show();

    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);


    queue.show();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.show();

    return 0;
}