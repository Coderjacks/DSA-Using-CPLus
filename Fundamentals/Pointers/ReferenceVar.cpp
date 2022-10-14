/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int a=10;
    int &r=a;
    printf("%d\n%d\n",a,r);
     r=90;
    printf("%d\n%d\n",a,r);
    a=20;
     printf("%d\n%d\n",a,r);
     printf("%d\n%d\n",sizeof(a),sizeof(r));
     printf("%d\n%d\n",&a,&r);
      
    return 0;
}
