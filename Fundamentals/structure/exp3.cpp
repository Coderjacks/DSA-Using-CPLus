#include<iostream>
using namespace std;

struct card
{
    int face;
    int shape;
    int color;
};

int main(){
                    //     strct1     struct2   struct3   struct4   struct5   struct6
    struct card deck[6][3]={{0,0,0} , {1,1,1} , {2,2,2} , {3,3,3} , {4,4,4} , {5,5,5}};

    for(int i=0; i<6; i++){
            for(int j=0; j<3;j++){
                cout<<deck[i][j].face;
                cout<<deck[i][j].shape;
                cout<<deck[i][j].color<<endl;
            }

    }


return 0;
}

