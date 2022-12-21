#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the length of ";
    cin>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the weight and val associated with it : ";
        cin>>wt[i]>>val[i];
    }
    int k;
    cout<<"enter the capacity of bag : ";
    cin>>k;
    int t[n+1][k+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<k+1;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    cout<<"\n max profit :  "<<t[n][k];
}