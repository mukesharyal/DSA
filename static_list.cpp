#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Node {
    int data;
    int next;
};

Node list[MAX_SIZE];
int avail[MAX_SIZE];
int head = -1, availHead = 0;

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

// a. Insert at the beginning of the list
void insertAtBeginning(int value) {
    int newNode = allocateNode();
    if (newNode == -1) return;
    list[newNode].data = value;
    list[newNode].next = head;
    head = newNode;
}

// b. Insert at the end of the list
void insertAtEnd(int value) {
    int newNode = allocateNode();
    if (newNode == -1) return;
    list[newNode].data = value;
    list[newNode].next = -1;

    if (head == -1) {
        head = newNode;
    } else {
        int temp = head;
        while (list[temp].next != -1) {
            temp = list[temp].next;
        }
        list[temp].next = newNode;
    }
}

// c. Insert after a specific element
void insertAfter(int afterValue, int value) {
    int temp = head;
    while (temp != -1 && list[temp].data != afterValue) {
        temp = list[temp].next;
    }
    if (temp == -1) {
        cout << "Element " << afterValue << " not found." << endl;
        return;
    }
    int newNode = allocateNode();
    if (newNode == -1) return;
    list[newNode].data = value;
    list[newNode].next = list[temp].next;
    list[temp].next = newNode;
}

// d. Delete from the beginning of the list
void deleteFromBeginning() {
    if (head == -1) {
        cout << "List is empty." << endl;
        return;
    }
    int temp = head;
    head = list[head].next;
    deallocateNode(temp);
}

// e. Delete from the end of the list
void deleteFromEnd() {
    if (head == -1) {
        cout << "List is empty." << endl;
        return;
    }
    if (list[head].next == -1) {
        deallocateNode(head);
        head = -1;
        return;
    }
    int temp = head;
    while (list[list[temp].next].next != -1) {
        temp = list[temp].next;
    }
    deallocateNode(list[temp].next);
    list[temp].next = -1;
}

// f. Delete after a specific element
void deleteAfter(int afterValue) {
    int temp = head;
    while (temp != -1 && list[temp].data != afterValue) {
        temp = list[temp].next;
    }
    if (temp == -1 || list[temp].next == -1) {
        cout << "Element " << afterValue << " not found or has no successor." << endl;
        return;
    }
    int toDelete = list[temp].next;
    list[temp].next = list[toDelete].next;
    deallocateNode(toDelete);
}

// Display the list
void displayList() {
    int temp = head;
    while (temp != -1) {
        cout << list[temp].data << " -> ";
        temp = list[temp].next;
    }
    cout << "NULL" << endl;
}

int main() {
    initializeList();

    // Test cases
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAfter(10, 25);
    cout << "List after insertions: ";
    displayList();

    deleteFromBeginning();
    cout << "List after deleting from beginning: ";
    displayList();

    deleteFromEnd();
    cout << "List after deleting from end: ";
    displayList();

    deleteAfter(10);
    cout << "List after deleting after 10: ";
    displayList();

    return 0;
}
