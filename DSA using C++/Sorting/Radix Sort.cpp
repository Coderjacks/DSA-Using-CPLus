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
       void radixsort()
       {
           if(length > 0)
           {
                int buckets[10][10], buckets_counts[10], div = 1, largest, radix_count = 0;
                largest = data[0];
                for(int i = 1; i < length; i++)
                {
                    if(data[i] > largest)
                    {
                        largest = data[i];
                    }
                }
                while(largest > 0)
                {
                    radix_count++;
                    largest = largest / 10;
                }
                for(int i = 1; i <= radix_count; i++)
                {
                    for(int j = 0; j <= 9; j++)
                    {
                        buckets_counts[j] = 0;
                    }
                    for(int j = 0; j <= length - 1; j++)
                    {
                        int k = (data[j] / div) % 10;
                        buckets[k][buckets_counts[k]] = data[j];
                        buckets_counts[k]++;
                    }
                    int l = 0;
                    for(int j = 0; j <= 9; j++)
                    {
                        for(int k = 0; k < buckets_counts[j]; k++)
                        {
                            data[l] = buckets[j][k];
                            l++;
                        }
                    }
                    div = div * 10;
                }
           }
           else
           {
               cout<<"\nNo value to sort\n";
           }
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
            a.radixsort();
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nWrong choice entered\n";
        }
    }while(true);
    return 0;
}
