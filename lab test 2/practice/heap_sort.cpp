#include<iostream>

using namespace std;

void heapify(int i,int arr[],int n)
{
    int largest=i;
    int r=i*2+2;
    int l=i*2+1;

    if(l<n && arr[l]>arr[largest])
    {
        largest=l;
    }

    if(r<n && arr[r]>arr[largest])
    {
        largest=r;
    }

    if(largest!=i)
    {
        int t=arr[largest];
        arr[largest]=arr[i];
        arr[i]=t;

        heapify(largest,arr,n);
    }
}

void heap_sort(int arr[],int n)
{
    for(int i=n/2 -1; i>=0;i--)
    {
        heapify(i,arr,n);
    }
    for(int i=n-1;i>=0;i--)
    {
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        heapify(0,arr,i);
    }
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

    heap_sort(arr,n);

    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
