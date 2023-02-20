#include<iostream>
#include<string.h>
using namespace std;
class Stack
{
        char data[50];
        int max_size;
        int top;
    public:
        Stack()
        {
            max_size = 50;
            top = -1;
        }
        void push(char value)
        {
            if(top != max_size - 1)
            {
                top++;
                data[top] = value;
            }
            else
            {
                cout<<"\nStack is full\n";
            }
        }
        char pop()
        {
            if(top != -1)
            {
                char value = data[top];
                top--;
                return value;
            }
            else
            {
                cout<<"\nStack is empty\n";
                return -1;
            }
        }
        void reverse_string(char str[50])
        {
            int n = strlen(str);
            for(int i = 0; i < n; i++)
            {
                push(str[i]);
            }
            for(int i = 0; i < n; i++)
            {
                str[i] = pop();
            }
            cout<<"Reverse word: "<<str<<endl;
        }
};
int main()
{
    Stack s;
    char word[50];
    cout<<"Enter a word\n";
    cin>>word;
    s.reverse_string(word);
    return 0;
}
