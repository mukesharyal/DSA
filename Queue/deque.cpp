#include <iostream>

using namespace std;

class Deque
{
    private:
        int arr[7];
        int front = -1;
        int rear = -1;

    public:

        void addFromRear(int val)
        {
            if((rear + 1) % 7 == front) // If front and rear are side by side
            {
                cout << "Cannot add from the rear" << endl;
                return;
            }

            if(front == -1) // If the queue is empty
            {
                front = 0;
            }

            rear = (rear + 1) % 7;

            arr[rear] = val;
        }

        
        void addFromFront(int val)
        {
            if((front + 6) % 7 == rear) // If front and rear are side by side
            {
                cout << "Cannot add from the front" << endl;
                return;
            }

            if(rear == -1) // If the queue is empty
            {
                rear = 1;
                front = 1;
            }

            front = (front + 6) % 7;

            arr[front] = val;
        }


        void removeFromFront()
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


        void removeFromRear()
        {
            if(rear == -1) // If the queue is empty
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

            rear = (rear + 6) % 7;
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
    Deque queue;

    queue.addFromRear(1);
    queue.addFromRear(2);
    queue.addFromRear(3);
    queue.addFromRear(4);
    queue.addFromRear(5);
    queue.addFromRear(6);
    queue.addFromRear(7);

    queue.show();



    queue.removeFromFront();
    queue.removeFromFront();
    queue.removeFromFront();
    queue.removeFromFront();
    queue.removeFromFront();

    queue.show();




    queue.addFromFront(1);
    queue.addFromFront(2);
    queue.addFromFront(2);

    queue.show();



    queue.removeFromRear();
    queue.removeFromRear();
    queue.removeFromRear();

    queue.show();



    queue.addFromRear(5);
    queue.addFromRear(6);
    queue.addFromRear(7);

    queue.show();



    queue.removeFromFront();
    queue.removeFromFront();
    queue.removeFromFront();

    queue.show();


    return 0;
}