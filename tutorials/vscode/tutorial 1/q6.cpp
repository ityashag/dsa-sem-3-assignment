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
        //getline(cin,s);
        //getline(cin,s);
        cin>>s;

        cout<<"string before : "<<s;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='a'&& s[i]<'z') ||(s[i]>='A'&& s[i]<'Z'))
            {
                s[i]+=1;
            }
            else if(s[i]=='z')
            {
                s[i]='a';
            }
            else if(s[i]=='Z')
            {
                s[i]='A';
            }
        }
        cout<<"\nstring after : "<<s<<"\n";
    }
}