
#include<iostream>
using namespace std;
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
        int arr[(n)];
        cout<<"enter the element in the array (0,1) only : ";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        int s=0;
        int e=n-1;
        int mid;
        
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(arr[mid]==0)
            {
                s=mid+1;
            }
            else 
            e=mid-1;
        }
        cout<<s<<"\n";
        
        
        
    }
}

