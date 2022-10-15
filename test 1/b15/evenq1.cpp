
#include<iostream>
using namespace std;

class mstack{
    public:

    string data;
    mstack * next;

    mstack(string s)
    {
        this->data=s;
        this->next=NULL;
    }

    void push(mstack *& s,string d)
    {
        mstack * n =new mstack (d);
        if(s==NULL)
        {
            s=n;
            return;
        }
        else
        {
            n->next=s;
            s=n;
        }
    }
    bool isempty(mstack * & s)
    {
        if(s==NULL) return true;
        return false;

    }
    void pop(mstack * & s)
    {
        if(!s->isempty(s))
        {
            mstack * to_del=s;
            s=s->next;
            delete(to_del);
        }
    }

    string top(mstack *& s)
    {
        if(!s->isempty(s))
        {
            return s->data;
        }
    }

    void ins(mstack *& s,string g)
    {

        if(s->isempty(s) || (!s->isempty(s) && s->top(s)>=g))
        {
            s->push(s,g);
            return;
        }

        string k=s->top(s);
        s->pop(s);
        ins(s,g);
        s->push(s,k);

    }

    void acc(mstack * & s )
    {
        if(s->isempty(s)) return;

        string g=s->top(s);
        s->pop(s);

        acc(s);
        ins(s,g);
    }
};
int main()
{

    int n=5;
    mstack * s=NULL;
    for(int i=0;i<n;i++)
    {
        string d;
        cout<<"enter the name : ";
        cin>>d;
        s->push(s,d);

    }

    s->acc(s);
    cout<<"stack \n";

    while(!s->isempty(s))
    {
        cout<<s->top(s)<<endl;
        s->pop(s);
    }
}
