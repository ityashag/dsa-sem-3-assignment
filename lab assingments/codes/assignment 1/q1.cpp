
#include<iostream>
#include<vector>
using namespace std;
int binary_to_decimal(vector<int> &a)
{
    int n=0;
    for(int i=0;i<a.size();i++)
    {
        n=n*2+(a[i]);
    }
    return n;
    //cout<<"decimal : "<<n<<"\n";
}
int octal_to_decimal(vector<int> &a)
{
    int n=0;
    for(int i=0;i<a.size();i++)
    {
        n=n*8+(a[i]);
    }

    //cout<<"decimal : "<<n<<"\n";
    return n;
}
int hexa_to_decimal(vector<char> &a)
{
    int n=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<='9'&& a[i]>='0')
        n=n*16+(a[i]-'0');
        else 
        {
            n=n*16+(a[i]-'A'+10);

        }
    }

    //cout<<"decimal : "<<n<<"\n";
    return n;

}
vector<int> decimal_to_binary( int n)
{
    vector<int> a;

    while(n)
    {
        a.push_back(n%2);
        n=n/2;
    }

    for(int i=0;i<a.size()/2;i++)
    {
        int temp=a[i];
        a[i]=a[a.size()-1-i];
        a[a.size()-1-i]=temp;
    }
    return a;

}
vector<int> decimal_to_octal(int n)
{
    vector<int> a;
    while(n)
    {
        a.push_back(n%8);
        n=n/8;
    }

    for(int i=0;i<a.size()/2;i++)
    {
        int temp=a[i];
        a[i]=a[a.size()-1-i];
        a[a.size()-1-i]=temp;
    }
    return a;

}

vector<char> decimal_to_hexadecimal(int n)
{
    vector<char>  a; 
    while(n)
    {
        int temp=n%16;
        if(temp<10)
        {
            a.push_back('0'+temp);
        }
        else 
        {
            a.push_back('A'+(temp-10));
        }
        n=n/16;
    }

    for(int i=0;i<a.size()/2;i++)
    {
        int temp=a[i];
        a[i]=a[a.size()-1-i];
        a[a.size()-1-i]=temp;
    }
    return a;
}

template<typename t>
void print(vector<t> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i];
    }
    cout<<"\n";

}


void binary_to_hexadecimal()
{
    vector<int> a;
    int n;
    cout<<"ENTER -1 TO STOP";
    cin>>n;
    while(n!=-1)
    {
        a.push_back(n);
        cin>>n;
    }
    cout<<"\n BINARY :";
    print(a);
    int d=binary_to_decimal(a);
    vector<char> b;
    b=decimal_to_hexadecimal(d);
    cout<<"\n HEXADECIAML : ";
    print(b);

}
void hexadecimal_to_binary()
{
    vector<char> a;
    char n;
    cout<<"ENTER S TO STOP";
    cin>>n;
    while(n!='S')
    {
        a.push_back(n);
        cin>>n;
    }
    cout<<"\n HEXADECIMAL :";
    print(a);
    int d=hexa_to_decimal(a);
    vector<int> b;
    b=decimal_to_binary(d);
    cout<<"\n BINARY : ";
    print(b);

    
}
void binary_to_octal()
{
    vector<int> a;
    int n;
    cout<<"ENTER -1 TO STOP";
    cin>>n;
    while(n!=-1)
    {
        a.push_back(n);
        cin>>n;
    }
    cout<<"\n BINARY :";
    print(a);
    int d=binary_to_decimal(a);
    vector<int> b;
    b=decimal_to_octal(d);
    cout<<"\n OCTAL : ";
    print(b);

}
void octal_to_binary()
{
    vector<int> a;
    int n;
    cout<<"ENTER -1 TO STOP";
    cin>>n;
    while(n!=-1)
    {
        a.push_back(n);
        cin>>n;
    }
    cout<<"\n OCTAL :";
    print(a);
    int d=octal_to_decimal(a);
    vector<int> b;
    b=decimal_to_binary(d);
    cout<<"\n BINARY : ";
    print(b);

}
void octal_to_hexadecimal()
{
    vector<int> a;
    int n;
    cout<<"ENTER -1 TO STOP";
    cin>>n;
    while(n!=-1)
    {
        a.push_back(n);
        cin>>n;
    }
    cout<<"\n OCTAL :";
    print(a);
    int d=octal_to_decimal(a);
    vector<char> b;
    b=decimal_to_hexadecimal(d);
    cout<<"\n HEXADECIAML : ";
    print(b);

}
void hexadecimal_to_octal()
{
     vector<char> a;
    char n;
    cout<<"ENTER S TO STOP";
    cin>>n;
    while(n!='S')
    {
        a.push_back(n);
        cin>>n;
    }
    cout<<"\n HEXADECIMAL :";
    print(a);
    int d=hexa_to_decimal(a);
    vector<int> b;
    b=decimal_to_octal(d);
    cout<<"\n OCTAL : ";
    print(b);
    
}


int main()
{

    int t=1;
    while(t)
    {

        cout<<"ENTER 1 TO CONVERT DECIMAL TO BINARY TO DECIMAL \nENTER 2 TO CONVERT DECIMAL TO OCTAL TO DECIMAL\nENTER 3 TO CONVERT DECIMAL TO HEXADECIAML TO DECIMAL\nENTER 4 TO CONVERT BINARY TO HEXA\nENTER 5 TO CONVERT BINARY TO OCTAL\nENTER 6 TO CONVERT OCTAL TO BINARY\nENTER 7 TO CONVERT OCTAL TO HEXA\nENTER 8 TO CONVERT HEXA TO OCTAL\nENTER 9 TO CONVERT HEXA TO BINARY\nENTER 0 TO EXIT\nENTER YOUT CHOISE :  ";
        cin>>t;

        int n;
        vector<int> a;
        vector<char> b;

        switch(t)
        {
            case 1:
                cout<<"enter the integer : ";
                cin>>n;
                a=decimal_to_binary(n);
                cout<<"BINARY : ";
                print(a);
                n=binary_to_decimal(a);
                cout<<"DECIMAL : "<<n<<"\n";
                break;
            case 2:
                cout<<"enter the integer : ";
                cin>>n;
                a=decimal_to_octal(n);
                cout<<"OCTAL : ";
                print(a);
                n=octal_to_decimal(a);
                cout<<"DECIMAL : "<<n<<"\n";
                break;
            case 3:
                cout<<"enter the integer : ";
                cin>>n;
                b=decimal_to_hexadecimal(n);
                cout<<"HEXA : ";
                print(b);
                n=hexa_to_decimal(b);
                cout<<"DECIMAL : "<<n<<"\n";
                break;
            case 4:
                binary_to_hexadecimal();
                break;
            case 5:
                binary_to_octal();
                break;
            case 6:
                octal_to_binary();
                break;
            case 7:
                octal_to_hexadecimal();
                break;
            case 8:
                hexadecimal_to_octal();
                break;
            case 9:
                hexadecimal_to_binary();
                break;
        }
    }

    

}