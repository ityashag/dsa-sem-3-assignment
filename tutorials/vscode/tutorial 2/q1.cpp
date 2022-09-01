#include<iostream>
using namespace std;

class fraction{
     public:
    int x,y;
   
    fraction()
    {
        cout<<"ENTER THE VALUE OF X,Y : ";
        cin>>x>>y;
    }
   
    fraction(int val_x,int val_y )
    {
        x=val_x;
        y=val_y;
    }
     ~fraction()
    {
        //cout<<"\ndestructor is called . ";
    }
    int f_gcd(int a,int b)
    {
        if(b==0)return a;
        return f_gcd(b,a%b);
    }
    void reduce()
    {
        int h=f_gcd(x,y);
        x/=h;
        y/=h;
    }
    void print()
    {
        cout<<"X = "<<x<<" Y = "<<y<<"\n";
    }

    fraction operator + (fraction a)
    {
        fraction ans(1,1);
        ans.x=(this->x*a.y) + (this->y*a.x);
        ans.y=this->y*a.y;
        return ans;

    }
};
int main()
{
    fraction a(9,3);
    a.reduce();
    a.print();
    cout<<"\n";

    fraction b;
    b.reduce();
    b.print();
     
     fraction total(1,1);
     total= a+b;
     total.print();

}