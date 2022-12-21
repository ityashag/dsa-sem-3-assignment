#include<iostream>
using namespace std;


bool fp(int arr[],int n)
{
    int sum=0;
    int i,j;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0) return false;
    bool dp[sum/2 +1][n+1];
    for( i=0;i<=n;i++)
    {
        dp[0][i]=true;
    }
    for(i=1;i<=sum/2;i++)
    {
        dp[i][0]=false;
    }
    for(i=1;i<=sum/2;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=arr[j-1])
            {
                dp[i][j]=dp[i][j] || dp[i-arr[j-1]][j-1];
            }
        }
    }
    return dp[sum/2][n];
}
int main()
{
    int n;
    cout<<"enter the value of n ";
    cin>>n;
    int arr[n];
    cout<<"enter the elemnts of array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(fp(arr,n)==true)
    {
        cout<<"\npartition possible .";

    }
    else
    {
        cout<<"\npartition is not possible . ";

    }
}