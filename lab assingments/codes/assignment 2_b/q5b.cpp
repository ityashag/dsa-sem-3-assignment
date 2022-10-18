
//quick sort
#include<iostream>
using namespace std;
int partition(int arr[],int s,int e)
{
    int pivort=arr[e];
    int i=s-1;
    for(int k=s;k<=e-1;k++)
    {
        if(arr[k]<pivort)
        {
            swap(arr[i+1],arr[k]);
            i++;
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
    
}

void quick(int arr[],int s,int e)
{
    if(s>=e) return;
    int q=partition(arr,s,e);
    quick(arr,s,q-1);
    quick(arr,q+1,e);
    
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
        
            arr[i]=rand()/1000000;
        }

        
        quick(arr,0,n-1);
        
        cout<<"the sorted array is : ";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}
