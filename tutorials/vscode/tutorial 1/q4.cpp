#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;

void solve(int arr[],int n)
{
    if(n==0)
    {
        cout<<" invalid array  \n";
        return;
    }
    unordered_map<int ,bool>visited;
    cout<<"unique element are : ";
    for(int i=0;i<n;i++)
    {
        if(!visited[arr[i]])
        {
            cout<<arr[i]<<" ";
            visited[arr[i]]=1;
        }
    }
    cout<<"\n";
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