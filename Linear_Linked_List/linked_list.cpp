#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;

    Node* next;
};

class Linked_List
{
    private:
        Node* start = nullptr;

    public:

        void insertNodeAtBeginning(int val)
        {
            Node* node = new Node;

            node->data = val;


            if(start == nullptr) // The list is empty
            {

                node->next = nullptr;

            }
            else
            {
                Node* prevStart = start;

                node->next = prevStart;
            }

            start = node;
        }



        void insertNodeAtEnd(int val)
        {

            Node* node = new Node;

            node->data = val;

            node->next = nullptr;

            if(start == nullptr) // The list is empty
            {
                start = node;
            }
            else
            {
                Node* selectedNode = start;

                while(selectedNode->next != nullptr) // While we don't reach the end of the list, we keep traversing the list
                {
                    selectedNode = selectedNode->next;
                }

                selectedNode->next = node; // We've found the end, and the new ending node will be the one we just created
            }


        }



        void insertNodeBeforeSpecificNode()
        {
            if(start == nullptr)
            {
                cout << "The list is empty!";

                return;
            }

            int count = 0;
            int index;
            int val;

            Node* selectedNode = start;

            while(selectedNode->next != nullptr)
            {
                selectedNode = selectedNode->next;

                count++;
            }

            cout << endl << "The list looks like this right now: " << endl;

            show();

            cout << "Enter the index before which a new node is to be added: ";
            cin >> index;

            if(index >= count)
            {
                cout << "The given index is invalid!" << endl;

                return;
            }

            cout << "Enter the value to be added: ";
            cin >> val;

            count = 0;

            selectedNode = start;

            while(count != (index-1))
            {
                selectedNode = selectedNode->next;

                count++;
            }

            Node* node = new Node;

            node->data = val;

            Node* previousNext = selectedNode->next;

            selectedNode->next = node;

            node->next = previousNext;

            cout << "The new list looks like: " << endl;

            show();

        }




        void insertNodeAfterSpecificNode()
        {
            if(start == nullptr)
            {
                cout << "The list is empty!";

                return;
            }

            int count = 0;
            int index;
            int val;

            Node* selectedNode = start;

            while(selectedNode->next != nullptr)
            {
                selectedNode = selectedNode->next;

                count++;
            }

            cout << endl << "The list looks like this right now: " << endl;

            show();

            cout << "Enter the index after which a new node is to be added: ";
            cin >> index;

            if(index >= count)
            {
                cout << "The given index is invalid!" << endl;

                return;
            }

            cout << "Enter the value to be added: ";
            cin >> val;

            count = 0;

            selectedNode = start;

            while(count != index)
            {
                selectedNode = selectedNode->next;

                count++;
            }

            Node* node = new Node;

            node->data = val;

            Node* previousNext = selectedNode->next;

            selectedNode->next = node;

            node->next = previousNext;

            cout << "The new list looks like: " << endl;

            show();

        }


        void show()
        {
            if(start == nullptr)
            {
                cout << "The list is empty." << endl;

                return;
            }

            Node* next = start;

            do
            {
                cout << next->data << " -> ";

                next = next->next;

            } while(next != nullptr);

            cout << "Null" << endl;
        }


};

int main()
{
    Linked_List list;

    list.insertNodeAtBeginning(25);
    list.insertNodeAtBeginning(32);

    list.show();

    list.insertNodeAtBeginning(34);
    list.insertNodeAtBeginning(56);

    list.show();

    list.insertNodeAtEnd(24);
    list.insertNodeAtEnd(71);

    list.show();

    list.insertNodeAtBeginning(1);
    list.insertNodeAtBeginning(3);

    list.show();

    list.insertNodeBeforeSpecificNode();
    list.insertNodeBeforeSpecificNode();

    list.insertNodeAfterSpecificNode();
    list.insertNodeAfterSpecificNode();

    return 0;
}