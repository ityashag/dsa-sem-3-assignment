#include<iostream>
using namespace std;

int main()
{
    int t;
    cout<<"enter test case : ";
    cin>>t;
    while(t--)
    {
        string s;
        cout<<"enter string : ";
        fflush(stdin);
        getline(cin,s);
        fflush(stdin);

        string temp="",ans="";
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='a'&& s[i]<='z') ||(s[i]>='A'&& s[i]<='Z'))
            {
                temp+=s[i];
            }
            else
            {
                if(temp.length()>ans.length())
                {
                    ans=temp;
                }
                temp="";
            }
        }
        if(temp.length()>ans.length())
        {
            ans=temp;
        }
                
        cout<<"\nlargest word in the string is : "<<ans<<"\n";
    }
}