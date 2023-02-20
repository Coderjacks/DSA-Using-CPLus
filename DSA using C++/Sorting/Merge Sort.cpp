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
       void merge_sort(int lower, int upper)
       {
           if(lower < upper)
           {
               int mid = (lower + upper) / 2;
               merge_sort(lower, mid);
               merge_sort(mid + 1, upper);
               int left = lower;
               int right = mid + 1;
               int i = lower;
               int t[10];
               while(left <= mid && right <= upper)
               {
                   if(data[left] <= data[right])
                   {
                       t[i] = data[left];
                       left++;
                       i++;
                   }
                   else
                   {
                       t[i] = data[right];
                       right++;
                       i++;
                   }
               }
               if(left > mid)
               {
                   while(right <= upper)
                   {
                       t[i] = data[right];
                       right++;
                       i++;
                   }
               }
               else if(right > upper)
               {
                   while(left <= mid)
                   {
                       t[i] = data[left];
                       left++;
                       i++;
                   }
               }
               for(int i = lower; i <= upper; i++)
               {
                    data[i] = t[i];
               }
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
            a.merge_sort(0, a.get_upper());
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
