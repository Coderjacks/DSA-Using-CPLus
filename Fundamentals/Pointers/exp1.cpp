#include<iostream>
using namespace std;
template <class h>
void pointer()
{
    int x=5;
    cout<<x<<endl;
    cout<<&x<<endl;//referencing operator or Address of operator
    cout<<*(&x)<<endl;


}
int main()
{
    pointer();
}
