#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void PrintLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int SizeOfLinkedList(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void InsertAtfirst(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtLast(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void InsertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        InsertAtfirst(head, data);
    }
    else if (position - 1 == SizeOfLinkedList(head))
    {
        InsertAtLast(tail, data);
    }
    else
    {

        int i = 1;
        Node *temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        Node *insertNode = new Node(data);
        insertNode->next = temp->next;
        temp->next = insertNode;
    }
}

void DeleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    else if (position == SizeOfLinkedList(head))
    {
        int i = 1;
        Node *temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        tail = temp;
        Node *DeleteNode = temp->next;
        temp->next = NULL;
        delete DeleteNode;
    }

    else
    {  
       int i = 1;
        Node *temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        
        Node *DeleteNode = temp->next;
        temp->next=temp->next->next;
        DeleteNode->next=NULL;

    }
}

int main()
{

    Node *Node1 = new Node(10);
    Node *head = Node1;
    Node *tail = Node1;
    PrintLinkedList(head);

    InsertAtfirst(head, 12);
    PrintLinkedList(head);

    InsertAtLast(tail, 15);
    PrintLinkedList(head);

    InsertAtPosition(head, tail, 2, 17);
    cout << SizeOfLinkedList(head) << endl;

    InsertAtPosition(head, tail, 4, 19);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    InsertAtPosition(head, tail, 5, 34);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    InsertAtPosition(head, tail, 3, 119);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    InsertAtPosition(head, tail, 8, 67);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    InsertAtPosition(head, tail, 8, 65);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    InsertAtPosition(head, tail, 1, 1);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    DeleteAtPosition(head, tail, 1);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    DeleteAtPosition(head, tail, 9);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    DeleteAtPosition(head, tail, 8);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    DeleteAtPosition(head, tail, 2);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;

    DeleteAtPosition(head, tail, 4);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;
}