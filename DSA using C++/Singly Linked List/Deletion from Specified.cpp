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
   void insert_at_end()
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
                first = current;
            }
            else
            {
                last->next = current;
            }
            last = current;
            last->next = NULL;
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
            cout<<"\nNode values of linked list are\n";
            Node *pos = first;
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
    void delete_from_specified()
    {
        if(first != NULL)
        {
            int node_no, value;
            Node *before, *pos;
            cout<<"\nEnter the node number\n";
            cin>>node_no;
            if(node_no >= 1 && node_no <= nodes_count)
            {
                if(node_no == 1)
                {
                    pos = first;
                    first = first->next;
                }
                else
                {
                    before = first;
                    for(int i = 1; i <= node_no - 2; i++)
                    {
                        before = before->next;
                    }
                    pos = before->next;
                    before->next = pos->next;
                }
                value = pos->data;
                delete pos;
                nodes_count--;
                cout<<"\nValue of node "<<node_no<<" deleted from specified position: "<<value<<endl;
            }
            else
            {
                cout<<"\nInvalid node number\n";
            }
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
        cout<<"\nEnter 1 to insert at end of singly linked list\n";
        cout<<"Enter 2 to traverse the singly linked list\n";
        cout<<"Enter 3 to delete from specified position in singly linked list\n";
        cout<<"Enter 4 to exit from program\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            sll.insert_at_end();
            break;
        case 2:
            sll.traverse();
            break;
        case 3:
            sll.delete_from_specified();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
