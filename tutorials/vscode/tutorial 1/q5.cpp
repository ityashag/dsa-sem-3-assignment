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

        cout<<"string before reverse : "<<s;
        for(int i=0;i<s.length()/2;i++)
        {
            char a=s[s.length()-1-i];
            s[s.length()-1-i]=s[i];
            s[i]=a;
        }
        cout<<"\nstring after reverse : "<<s<<"\n";
    }
}