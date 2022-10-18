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
    int i=0;
    int j,lp=1,up=1;

    int lower[n],upper[n],b[n];

    for(i=0;i<n;i++)
    {
        lower[i]=lp;
        lp*=a[i];

        j=n-1-i;

        upper[j]=up;
        up*=a[j];

    }

    while(i--)
    {
        b[i]=lower[i]*upper[i];
    }

    cout<<" b : ";
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }

}