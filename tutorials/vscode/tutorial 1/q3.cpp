#include<iostream>
#include<unordered_map>
using namespace std;

void solve(int arr[],int n)
{
    if(n==0)
    {
        cout<<" invalid array  \n";
        return;
    }

    unordered_map< int,int> m; // create hash map 
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
     cout<<"repeated elements are : ";
    for(auto i:m)
    {
       
        if(i.second>1)
        {
            cout<<i.first<<" ";
        }
       
    }
     cout<<"\n";
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