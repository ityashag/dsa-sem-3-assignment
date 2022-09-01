
#include<iostream>
using namespace std;

void solve(int arr[],int s,int e,int key)
{
    int mid=s+(e-s)/2;
    if(s>e)
    {
        cout<<"the element is not present \n ";
        return;
    }

    if(arr[mid]==key)
    {
        cout<<"the element is present : \n";
        return;
    }
    else if(arr[mid]>key)
    {

        e=mid-1;
        solve(arr,s,e,key);
    }
    else{ s=mid+1;
        solve(arr,s,e,key);
    }

}
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

        // sorting
        int j;
        for(int i=1;i<n;i++)
        {

            int temp =arr[i];
            for(j=i-1;j>=0;j--)
            {
                if(arr[j]>temp)
                {

                    arr[j+1]=arr[j];
                }
                else
                {
                    break;
                }
            }
            arr[j+1]=temp;
        }
         int key;
         cout<<"enter the key : ";
         cin>>key;

         solve(arr,0,n-1,key);

    }
}
