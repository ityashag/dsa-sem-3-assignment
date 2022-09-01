#include<iostream>
using namespace std;


int main()
{
    int n;
    cout<<"enter the number of elements of array :";
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cout<<"enter the "<<i+1<<"th element : ";
        cin>>a[i];

    }

    //sort

    for(int i=0;i<n;i+=2)
    {
        if(a[i-1]>=a[i] && i-1>=0)
        {
            swap(a[i-1],a[i]);
        }
        if(a[i+1]>=a[i] && i+1<=n-1)
        {
            swap(a[i+1],a[i]);

        }
    }

    cout<<" wave array : ";

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<< " ";

    }
}