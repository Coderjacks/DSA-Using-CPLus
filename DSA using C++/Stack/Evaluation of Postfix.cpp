#include<iostream>
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
        bool isoperand(char symbol)
        {
            if(symbol >= '0' && symbol <= '9')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void evaluate_postfix()
        {
            char postfix[50];
            int leftoperand, rightoperand, result;
            cout<<"Enter the postfix expression\n";
            cin>>postfix;
            for(int i = 0; postfix[i] != '\0'; i++)
            {
                if(isoperand(postfix[i]))
                {
                    push(postfix[i] - '0');
                }
                else
                {
                    rightoperand = pop();
                    leftoperand = pop();
                    switch(postfix[i])
                    {
                        case '+':
                            result = leftoperand + rightoperand;
                            break;
                        case '-':
                            result = leftoperand - rightoperand;
                            break;
                        case '*':
                            result = leftoperand * rightoperand;
                            break;
                        case '/':
                            result = leftoperand / rightoperand;
                            break;
                        case '%':
                            result = leftoperand % rightoperand;
                            break;
                    }
                    push(result);
                }
            }
            cout<<result;
        }
};
int main()
{
    Stack s;
    s.evaluate_postfix();
    return 0;
}
