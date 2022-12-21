#include<iostream>
using namespace std;


// int longest_substring(string s,int ct,int &k,int i,int n,int l)
// {
//     cout<<s<<endl;
//     if(s.length()==0)
//     {
//         return 0;
//     }
//     if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
//     {
//         if(ct<k)
//         {
//             return max(1+longest_substring(s.substr(0,n-l),ct+1,k,i-1,n,l+1),longest_substring(s.substr(0,n-l),0,k,i-1,n,l+1));
//         }
//         else
//         {
//             int a =n-s.length();
//             return max(1,longest_substring(s.substr(0,n-l),0,k,i-1,n,l+1));
//         }
        
//     }
//     else
//     {
//         return 1+longest_substring(s.substr(0,n-l),ct,k,i-1,n,l+1);
//     }
// }

// int main()
// {
//     string s;
//     getline(cin,s);
//     int n=s.length();
//     // s="artyebui";
//     int l=1;
//     int k=2;
//     cout<<longest_substring(s,0,k,n-1,n,l);
// }

int main()
{
    string s;
    cout<<"enter the string : ";
    getline(cin,s);
    int n=s.length();
    cout<<"enter the value of k : ";
    int k;
    cin>>k;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int ct=0;
        for(int j=i;j<n;j++)
        {
            if(s[j]=='a' || s[j]=='e' || s[j]=='o' ||  s[j]=='u' ||  s[j]=='i')
            {
                ct++;
                if(ct<=k)
                {
                    ans=max(ans,j-i+1);
                }
                else if(ct>k)break;
            }
            else
            {
                ans = max(ans,j-i+1);
            }
        }
    }

    cout<<"\nlongest substring with k vowels: "<<ans;

}



