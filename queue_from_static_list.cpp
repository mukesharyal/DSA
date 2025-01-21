#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Node {
    int data;
    int next;
};

Node list[MAX_SIZE];
int avail[MAX_SIZE];
int front = -1, rear = -1, availHead = 0;

// Initialize the list and availability array
void initializeList() {
    for (int i = 0; i < MAX_SIZE; i++) {
        avail[i] = i + 1;
    }
    avail[MAX_SIZE - 1] = -1;
}

// Allocate a node from the avail list
int allocateNode() {
    if (availHead == -1) {
        cout << "No available space in the list." << endl;
        return -1;
    }
    int newNode = availHead;
    availHead = avail[availHead];
    return newNode;
}

// Deallocate a node and add it back to the avail list
void deallocateNode(int index) {
    avail[index] = availHead;
    availHead = index;
}

// Enqueue operation
void enqueue(int value) {
    int newNode = allocateNode();
    if (newNode == -1) return;
    list[newNode].data = value;
    list[newNode].next = -1;

    if (front == -1) {
        front = rear = newNode; // Queue was empty
    } else {
        list[rear].next = newNode;
        rear = newNode;
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }
    int temp = front;
    front = list[front].next;
    if (front == -1) {
        rear = -1; // Queue becomes empty
    }
    deallocateNode(temp);
}

// Display the queue
void displayQueue() {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }
    int temp = front;
    while (temp != -1) {
        cout << list[temp].data << " -> ";
        temp = list[temp].next;
    }
    cout << "NULL" << endl;
}

int main() {
    initializeList();

    // Test cases for the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << "Queue after enqueues: ";
    displayQueue();

    dequeue();
    cout << "Queue after one dequeue: ";
    displayQueue();

    enqueue(40);
    cout << "Queue after another enqueue: ";
    displayQueue();

    dequeue();
    dequeue();
    cout << "Queue after two more dequeues: ";
    displayQueue();

    dequeue();
    cout << "Queue after dequeuing all elements: ";
    displayQueue();

    return 0;
}
