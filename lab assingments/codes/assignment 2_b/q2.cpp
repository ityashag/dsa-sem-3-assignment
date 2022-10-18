#include<iostream>
using namespace std;

//insertion sort
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
        int j;
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
        }
        
        
        cout<<"the sorted array is : ";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}