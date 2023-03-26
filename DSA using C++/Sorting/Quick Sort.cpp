#include<iostream>
#include<stdlib.h>
using namespace std;
class Array
{
   int data[10];
   int max_size;
   int length;
   public:
       Array()
       {
           max_size = 10;
           length = 0;
       }
       void insert_at_end()
       {
           if(length < max_size)
           {
               int value;
               cout<<"\nEnter the value\n";
               cin>>value;
               data[length] = value;
               length++;
           }
           else
           {
               cout<<"\nArray is full\n";
           }
       }
       void traverse()
       {
           if(length > 0)
           {
                cout<<"\nValue of array are\n";
                for(int i = 0; i <= length - 1; i++)
                {
                    cout<<data[i]<<" ";
                }
                cout<<endl;
           }
           else
           {
               cout<<"\nNo value to traverse\n";
           }
       }
       void quick_sort(int lower, int upper)
       {
           if(lower < upper)
           {
                int pivot, left, right;
                pivot = lower;
                left = lower + 1;
                right = upper;
                while(right >= left)
                {
                    while(left <= upper && data[left] <= data[pivot])
                    {
                        left++;
                    }
                    while(right >= lower && data[right] > data[pivot])
                    {
                        right--;
                    }
                    if(left < right)
                    {
                        int t = data[left];
                        data[left] = data[right];
                        data[right] = t;
                    }
                }
                int t = data[pivot];
                data[pivot] = data[right];
                data[right] = t;
                pivot = right;
                quick_sort(lower, pivot - 1);
                quick_sort(pivot + 1, upper);
           }
       }
       int get_upper()
       {
           return length - 1;
       }
};
int main()
{
    Array a;
    int ch;
    do
    {
        cout<<"\nEnter 1 to add value at end of array\n";
        cout<<"Enter 2 to traverse values of array\n";
        cout<<"Enter 3 to sort values of array\n";
        cout<<"Enter 4 to exit from program\n";
        cout<<"\nEnter your choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            a.insert_at_end();
            break;
        case 2:
            a.traverse();
            break;
        case 3:
            a.quick_sort(0, a.get_upper());
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
