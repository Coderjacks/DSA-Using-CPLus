#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class HashTable
{
    Node* table[10];
    int SIZE;
public:
    HashTable()
    {
        SIZE = 10;
        for(int i = 0; i < SIZE; i++)
        {
            table[i] = new Node();
            table[i]->data = -1;
            table[i]->next = NULL;
        }
    }
    int hashing(int value)
    {
        int key = value % SIZE;
        return key;
    }
    void add()
    {
        int value, key;
        cout<<"\nEnter the value: ";
        cin>>value;
        key = hashing(value);
        if(table[key]->data == -1)
        {
            table[key]->data = value;
        }
        else
        {
            Node *current = new Node();
            current->data = value;
            current->next = NULL;
            Node *pos = table[key];
            while(pos->next != NULL)
            {
                pos = pos->next;
            }
            pos->next = current;
        }
    }
    void traverse()
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(table[i]->data != -1)
            {
                Node *pos = table[i];
                while(pos != NULL)
                {
                    cout<<pos->data<<" ";
                    pos = pos->next;
                }
            }
        }
        cout<<endl;
    }
    void search()
    {
        int value, key;
        cout<<"\nEnter the value: ";
        cin>>value;
        key = hashing(value);
        if(table[key]->data != -1)
        {
            bool found = false;
            Node *pos = table[key];
            while(pos != NULL)
            {
                if(value == pos->data)
                {
                    found = true;
                    break;
                 }
                 pos = pos->next;
            }
            if(found)
            {
                cout<<"\n"<<value<<" is present\n";
            }
            else
            {
                cout<<"\n"<<value<<" is not present\n";
            }
        }
        else
        {
            cout<<"\n"<<value<<" is not present\n";
        }
    }
    void del()
    {
        int value, key;
        cout<<"\nEnter the value: ";
        cin>>value;
        key = hashing(value);
        if(table[key]->data != -1)
        {
            bool found = false;
            if(value == table[key]->data)
            {
                found = true;
                if(table[key]->next == NULL)
                {
                    table[key]->data = -1;
                }
                else
                {
                    Node *pos = table[key];
                    table[key] = pos->next;
                    delete pos;
                }
            }
            else
            {
                Node* prev, *pos;
                prev = table[key];
                pos = prev->next;
                while(pos != NULL)
                {
                    if(value == pos->data)
                    {
                        found = true;
                        prev->next = pos->next;
                        delete pos;
                        break;
                     }
                     prev = pos;
                     pos = pos->next;
                 }
            }
            if(found)
            {
                cout<<"\n"<<value<<" is deleted successfully\n";
            }
            else
            {
                cout<<"\n"<<value<<" is not present\n";
            }
        }
        else
        {
            cout<<"\n"<<value<<" is not present\n";
        }
    }
};
int main()
{
    HashTable ht;
    int ch;
    do
    {
        cout<<"\nEnter 1 to add value to hash table\n";
        cout<<"Enter 2 to view values of hash table\n";
        cout<<"Enter 3 to search value in hash table\n";
        cout<<"Enter 4 to delete value from hash table\n";
        cout<<"Enter 5 to exit from program\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            ht.add();
            break;
        case 2:
            ht.traverse();
            break;
        case 3:
            ht.search();
            break;
        case 4:
            ht.del();
            break;
        case 5:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
