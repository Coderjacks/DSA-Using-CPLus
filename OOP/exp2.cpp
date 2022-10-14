#include<iostream>
using namespace std;
class greatest
{
    int n1,n2;
public:
    greatest(int a,int b)
    {
        n1=a;
        n2=b;

    }
    void g1()
    {
        if(n1>n2){
            cout<<n1<<">"<<n2;
        }
        else if(n2>n1){
            cout<<n1<<"<"<<n2;
        }
        else{
            cout<<n1<<"="<<n2;
        }
    }
};
int main()
{
    int x,y;
    cout<<"Enter two numbers"<<endl;
    cin>>x>>y;
    greatest gr(x,y);
    gr.g1();
}
