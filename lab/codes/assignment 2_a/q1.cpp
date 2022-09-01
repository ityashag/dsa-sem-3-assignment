
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
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cout<<"enter the "<<i+1<<"th element : ";
            cin>>arr[i];
        }

        // sorting
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

        int k=0;

        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i+1])
            {
                k++;
                i++;

                while(arr[i]==arr[i+1]) i++;

            }
            else k++;
        }
        int arrnew[k];
        int l=0;

        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i+1])
            {
               arrnew[l++]=arr[i];
                i++;

                while(arr[i]==arr[i+1]) i++;

            }
            else arrnew[l++]=arr[i];
        }
        cout<<"\n the array of unique element is : ";
        for(int i=0;i<k;i++)
        {
            cout<<arrnew[i]<<" ";

        }
    }
}
