#include<iostream>
using namespace std;
class digit
{
   int n;
   int c;
   public:
       digit(int n){

            c=0;
            this-> n=n;
       }
       void d()
       {
            while(n>0)
             {
               c++;
               n=n/10;
             }
             cout<<c;
        }
};
int main()
{
    int a;
    cin>>a;
    digit d1(a);
    d1.d();
}
