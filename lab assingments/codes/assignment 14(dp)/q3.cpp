#include<iostream>
using namespace std;


//kadane algorithm  
// T(n) = 0(n)
// s(n) = 0(1)
void solve(int arr[],int n)
{
    int sum=INT_MIN ,curr=0;
    int i=0;    
    while(i<n)
    {
        curr=curr+arr[i];
        if(curr>sum)
        {
            sum=max(curr,sum);
        }
        if(curr<0)
        {
            curr=0;
        }
        i++;
    }
    cout<<"the largest sum of subbarray : "<<sum<<"\n";
    
}

int main()
{

    int t;
    cout<<"enter number of test case : ";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter the number of element in an array : ";
        cin>>n;
        int arr[n];
        cout<<"enter the elements in the array : ";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
    }
}