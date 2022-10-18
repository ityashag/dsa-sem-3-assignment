
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
        cout<<"\nenter the number element in the array1: ";
        cin>>n;
        int arr1[(n+1)];
        cout<<"enter the element in the array1 : ";
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        
         int m;
        cout<<"\nenter the number element in the array2 : ";
        cin>>m;
        int arr2[m+1];
        cout<<"enter the element in the array2 : ";
        for(int i=0;i<m;i++)
        {
            cin>>arr2[i];
        }
        int kk;
        cout<<"enter the value of k ";
        cin>>kk;
        
        
    int arr[m+n];
    int large=max(arr1[n-1],arr2[m-1])+1;
    arr1[n]=large;
    arr2[m]=large;
    int i=0,j=0;

    for(int k=0;k<n+m;k++)
    {
        if(arr1[i]<arr2[j])arr[k]=arr1[i++];
        else arr[k]=arr2[j++];
    }
    cout<<"the kth shorted element in M+N sorted array is "<<arr[kk-1]<<"\n";
    }
}
