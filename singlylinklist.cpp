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
    else if (position-1 == SizeOfLinkedList(head))
    {
        InsertAtLast(tail, data);
    }
    else{}
    // {  int i=0;
    //    Node* prev=head;
    //    Node* current;
    //    while(i<position)
    //    {
    //      i++;
    //      current=prev->next;
    //      prev-next;
    //    }
    
}

void DeleteAtPosition(Node *&head, Node *&tail, int position)
{
   if (position == 1)
    {
       Node *temp=head;
       head=head->next;

       temp->next=NULL;
       delete temp;

    }
    else if (position-1 == SizeOfLinkedList(head))
    {
      
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

    DeleteAtPosition(head, tail, 1);
    PrintLinkedList(head);
    cout << SizeOfLinkedList(head) << endl;


}