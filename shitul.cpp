#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *prev, *next;
    Node(int x) /// constructor
    {
        data = x;
    }
};

struct DL_List
{
    Node* head,*tail;
    DL_List(); /// constructor
    ~DL_List(); /// destructor
    void insertAtEnd(int data);
    int deleteFromBeginning();
    void printList();
};

void DL_List:: insertAtEnd(int data)
{
    Node * temp=new Node(data);
    temp->next=temp->prev=NULL;

    if(head==NULL)
        head=tail=temp;
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }

}
int DL_List::deleteFromBeginning()
{
    int deleted_data;
    Node*temp=head;

    if(head!=NULL)
    {
        deleted_data=head->data;

        if(head->next==NULL)
        {
            head=NULL;
        }
        else
        {
            head=head->next;
            head->prev=NULL;
        }

        delete temp;

        return(deleted_data);
    }
    return(-1);
}

void DL_List::printList()
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<"\t"<<temp->data;
        temp=temp->next;
    }
    cout<<"\n---- Ended ----";
}
DL_List::DL_List()
{
    head=tail=NULL;
}
DL_List::~DL_List()
{
    delete head;
    delete tail;
}

struct Queue
{
    DL_List Q;
    Queue() {}
    void enqueue(int data); /// to insert an element into the queue
    void dequeue(); /// to delete an element from the queue
    void display(); /// to print the queue from head to tail
    bool isEmpty(); /// checking for Underflow
};
void Queue::enqueue(int data)
{
    Q.insertAtEnd(data);
}
void Queue::dequeue()
{
    int deleted_data=Q.deleteFromBeginning();
    if(deleted_data!=-1)
        cout<<"\nDeleted data: "<<deleted_data;
    else
        cout<<"\nNothing to delte.";
}
void Queue::display()
{
    Q.printList();
}
bool Queue::isEmpty()
{
    if(Q.head==NULL)
        return true;
    return false;
}
int main()
{
    int choice,data;
    Queue queue;

    while(1)
    {

        cout<<"\n---------MENU----------\n\n1. Insert at the beginning\n2. Delete from the beginning\n3.Display\n4.check empty\n5.Exit\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
        {
            cout<<"\nEnter your data:";
            cin>>data;
            queue.enqueue(data);
            break;
        }
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        case 4:
            cout<<(queue.isEmpty()?"\nQueue is empty\n\n":"\nQueue contains some elements\n\n");
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"\nInvalid option.";
        }
    }

    return 0;
}
