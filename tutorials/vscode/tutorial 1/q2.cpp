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

    cout<<"enter the key : ";
    int key;
    cin>>key;
    int count=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==key) count++;
    }
    cout<<"Number of occurrences of "<<key<<" is: "<<count<<"\n";
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