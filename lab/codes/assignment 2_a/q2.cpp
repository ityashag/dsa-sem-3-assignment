#include<iostream>
using namespace std;

int main()
{
    int t;
    cout<<"enter the number of test case : ";
    cin>>t;
    while(t--)
    {

        int n;
        cout<<"\nenter the number element in the array: ";
        cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cout<<"enter the "<<i+1<<"th element : ";
            cin>>arr[i];
        }
         int key;
         cout<<"enter the key : ";
         cin>>key;

         for(int i=0;i<n;i++ )
         {
            if(arr[i]==key)
            {

                cout<<"the key is present : ";
                break;
            }

         }
         cout<<"the key is not present ";
        }
    }
}
