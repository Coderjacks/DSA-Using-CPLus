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
        bool isoperator(char symbol)
        {
            if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int getpriority(char symbol)
        {
            if(symbol == '+' || symbol == '-')
            {
                return 1;
            }
            else if(symbol == '*' || symbol == '/' || symbol == '%')
            {
                return 2;
            }
        }
        void infixtopostfix()
        {
            char infix[50], postfix[50], symbol;
            int j = 0;
            cout<<"Enter the infix expression\n";
            cin>>infix;
            strcat(infix, ")");
            push('(');
            for(int i = 0; infix[i] != '\0'; i++)
            {
                if(infix[i] == '(')
                {
                    push(infix[i]);
                }
                else if(isoperator(infix[i]))
                {
                    while(isoperator(data[top]) && (getpriority(data[top]) >= getpriority(infix[i])))
                    {
                        symbol = pop();
                        postfix[j] = symbol;
                        j++;
                    }
                    push(infix[i]);
                }
                else if(infix[i] == ')')
                {
                    while((symbol = pop()) != '(')
                    {
                        postfix[j] = symbol;
                        j++;
                    }
                }
                else
                {
                    postfix[j] = infix[i];
                    j++;
                }
            }
            postfix[j] = '\0';
            cout<<postfix;
        }
};
int main()
{
    Stack s;
    s.infixtopostfix();
    return 0;
}
