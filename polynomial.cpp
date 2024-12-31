#include <iostream>

using namespace std;

struct Node
{
    int coeff;

    int exp;

    Node* next;
};

class Polynomial
{
    private:

        Node* start = nullptr;

        Node* current = nullptr;


    public:

        void addNode(int coeffi, int expo)
        {
            Node* node = new Node;

            node->coeff = coeffi;
            node->exp = expo;

            if(start == nullptr)
            {
                start = node;
            }
            else
            {
                current->next = node;
            }

            current = node;
            node->next = nullptr;
        }



        Polynomial operator + (Polynomial p)
        {
            Polynomial result;

            Node* pCurrent = p.start;

            Node* qCurrent = start;

            while(pCurrent != nullptr || qCurrent != nullptr)
            {
                if(pCurrent == nullptr)
                {
                    while(qCurrent != nullptr)
                    {
                        result.addNode(qCurrent->coeff, qCurrent->exp);

                        qCurrent = qCurrent->next;
                    }

                    break;
                }

                if(qCurrent == nullptr)
                {
                    while(pCurrent != nullptr)
                    {
                        result.addNode(pCurrent->coeff, pCurrent->exp);

                        pCurrent = pCurrent->next;
                    }

                    break;

                }

                int expo1 = pCurrent->exp;

                int expo2 = qCurrent->exp;

                if(expo1 == expo2)
                {
                    result.addNode((pCurrent->coeff + qCurrent->coeff), expo1);

                    pCurrent = pCurrent->next;

                    qCurrent = qCurrent->next;
                }
                else if(expo1 < expo2)
                {
                    result.addNode((qCurrent->coeff), expo2);

                    qCurrent = qCurrent->next;
                }
                else
                {
                    result.addNode((pCurrent->coeff), expo1);

                    pCurrent = pCurrent->next;
                }

            }


            return result;


        }


        void display()
        {
            Node* selectedNode = start;

            while(selectedNode != nullptr)
            {
                cout << selectedNode->coeff << "x" << selectedNode->exp << endl;

                selectedNode = selectedNode->next;
            }
        }
};


int main()
{

    Polynomial p;
    Polynomial q;
    Polynomial result;


    p.addNode(3, 3);
    p.addNode(-2, 1);
    p.addNode(6, 0);

    q.addNode(6, 3);
    q.addNode(8, 2);

    result = p + q;

    result.display();

    return 0;
}
