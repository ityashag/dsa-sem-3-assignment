#include<iostream>

using namespace std;

int partition(int arr[],int p,int q)
{
    int i=p-1;
    int x=arr[q];

    for(int j=p;j<q;j++)
    {
        if(arr[j]<x)
        {
            int t=arr[i+1];
            arr[i+1]=arr[j];
            arr[j]=t;
            i++;
        }
    }

    int t=arr[q];
    arr[q]=arr[i+1];
    arr[i+1]=t;

    return i+1;
}

void quick_sort(int arr[],int s,int e)
{
    if(s>=e) return;

    int p=partition(arr,s,e);
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}

int main()
{
    int n;
    cout<<"enter n : ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    quick_sort(arr,0,n-1);

    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}

