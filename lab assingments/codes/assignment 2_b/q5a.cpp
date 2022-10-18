
//merge sort
#include<iostream>
using namespace std;

void mergesort(int arr[],int s,int q,int e)
{
    int n1=q-s+1;
    int n2=e-q;
    int l[n1+1],r[n2+1];

    int j=0;

    for(int i=s;i<=q;i++)
    {
        l[j++]=arr[i];
    }
    j=0;
    for(int i=q+1;i<=e;i++)
    {
        r[j++]=arr[i];
    }
    int large=max(l[n1-1],r[n2-1])+1;
    l[n1]=large;
    r[n2]=large;
    int i=0;
    j=0;

    for(int k=s;k<=e;k++)
    {
        if(l[i]<r[j])arr[k]=l[i++];
        else arr[k]=r[j++];
    }
}

void merge(int arr[],int s,int e)
{
    if(s==e) return;
    int q=s+(e-s)/2;
    merge(arr,s,q);
    merge(arr,q+1,e);
    mergesort(arr,s,q,e);
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

        // sorting

        /*int j;
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
        }*/
        
        merge(arr,0,n-1);
        
        cout<<"the sorted array is : ";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}
