#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int val = this->data;
        cout << "your value is " << val << "deleted now " << endl;
    }
};
void printLinkedList(Node *head)
{
    // Node * temp=head;
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;

    cout << endl;
}
int getlength(Node *head)
{
    int len = 0;
    while (head->next != NULL)
    {
        len++;
        head = head->next;
    }
    return ++len;
}
void insertAthead(Node *&head, int data)
{
    Node *temp = new Node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertAtposition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAthead(head, data);
    }
    else if (getlength(head) + 1 <= position)
    {
        insertAttail(tail, data);
    }
    else
    {
        //here is main code of insertion in linkedList
        int count=1;
        Node* temp=head;
        while(count<position-1)
        {
          count++;
          temp=temp->next;   
        }
        
        Node* nodetoInsert=new Node(data);
        nodetoInsert->next= temp->next;
        nodetoInsert->prev=temp;
        temp->next=nodetoInsert;
        temp->next->prev=nodetoInsert;
        //in this case there is no need update head and tail

    }
}
int main()
{
    Node *head = new Node(10);
    Node *tail = head;
    insertAthead(head, 12);
    insertAthead(head, 14);
    insertAthead(head, 16);
    
    printLinkedList(head);
    cout<<getlength(head)<<endl;
   
    insertAttail(tail, 20);
    printLinkedList(head);
    cout<<getlength(head)<<endl;;

    insertAtposition(head, tail, 1, 22);
    printLinkedList(head);
    cout<<getlength(head)<<endl;

    insertAtposition(head, tail, 7, 29);
    printLinkedList(head);
    cout<<getlength(head)<<endl;

    insertAtposition(head, tail, 4, 29);
    printLinkedList(head);
    cout<<getlength(head)<<endl;

    insertAtposition(head, tail,6,37);
    printLinkedList(head);
    cout<<getlength(head)<<endl;

}