#include<iostream>
using namespace std;

struct card
{
    int face;
    int shape;
    int color;
};

int main(){
                    //  strct1     struct2   struct3   struct4   struct5   struct6
    struct card deck[6]={{0,0,0} , {1,1,1} , {2,2,2} , {3,3,3} , {4,4,4} , {5,5,5}};
    cout<<sizeof(deck);
    cout<<deck[0].face;
    cout<<deck[0].shape;
    cout<<deck[0].color<<endl;
    //
    cout<<deck[1].face;
    cout<<deck[1].shape;
    cout<<deck[1].color<<endl;
    //
    cout<<deck[2].face;
    cout<<deck[2].shape;
    cout<<deck[2].color<<endl;
    //
    cout<<deck[3].face;
    cout<<deck[3].shape;
    cout<<deck[3].color<<endl;
    //
    cout<<deck[4].face;
    cout<<deck[4].shape;
    cout<<deck[4].color<<endl;
    //
    cout<<deck[5].face;
    cout<<deck[5].shape;
    cout<<deck[5].color<<endl;
//using loop;
    for(int i=0; i<6; i++){
    cout<<deck[i].face;
    cout<<deck[i].shape;
    cout<<deck[i].color<<endl;
    }


return 0;
}
