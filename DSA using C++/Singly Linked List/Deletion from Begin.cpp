#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class SinglyLinkedList
{
    Node *first;
    Node *last;
    int nodes_count;
public:
    SinglyLinkedList()
    {
        first = NULL;
        last = NULL;
        nodes_count = 0;
    }
    void insert_at_begin()
    {
        int value;
        Node *current = new Node;
        if(current != NULL)
        {
            cout<<"\nEnter the node value\n";
            cin>>value;
            current->data = value;
            if(first == NULL)
            {
                last = current;
                last->next = NULL;
            }
            else
            {
                current->next = first;
            }
            first = current;
            nodes_count++;
        }
        else
        {
            cout<<"\nMemory is not available\n";
        }
    }
    void traverse()
    {
        if(first != NULL)
        {
            Node *pos = first;
            cout<<"\nNode values of linked list are\n";
            while(pos != NULL)
            {
                cout<<pos->data<<" ";
                pos = pos->next;
            }
            cout<<endl;
        }
        else
        {
            cout<<"\nNo node value to traverse\n";
        }
    }
    void delete_from_begin()
    {
        if(first != NULL)
        {
            int value;
            Node *pos = first;
            if(first != last)
            {
                first = first->next;
            }
            else
            {
                first =  NULL;
                last = NULL;
            }
            value = pos->data;
            delete pos;
            nodes_count--;
            cout<<"\nValue of node deleted from begin: "<<value<<endl;
        }
        else
        {
            cout<<"\nSingly linked list is empty\n";
        }
    }
};
int main()
{
    int ch;
    SinglyLinkedList sll;
    do
    {
        cout<<"\nEnter 1 to insert at begin of singly linked list\n";
        cout<<"Enter 2 to traverse the singly linked list\n";
        cout<<"Enter 3 to delete from begin of singly linked list\n";
        cout<<"Enter 4 to exit from program\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            sll.insert_at_begin();
            break;
        case 2:
            sll.traverse();
            break;
        case 3:
            sll.delete_from_begin();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
