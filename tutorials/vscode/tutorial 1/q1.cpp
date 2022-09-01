#include<iostream>
using namespace std;

void solve(int arr[],int n)
{
    if(n==0)
    {
        cout<<" invalid array  \n";
        return;
    }
    int first=arr[0];

    for(int i=0;i<n;i++)
    {
        if(abs(first-arr[i])!=i)
        {
            cout<<"the missing element is : "<<abs(first-arr[i])+first-1<<" \n";
            return;
        }
    }

    cout<<"no element is missing \n";
    return;


}
int main()
{
    int t;
    cout<<"enter no of test case : ";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter number of elements in an array :";
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cout<<"enter "<<i+1<<" th element in the array : ";
            cin>>arr[i];
        }

        solve(arr,n);
    }
}