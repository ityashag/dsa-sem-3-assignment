#include <iostream>
#include<fstream>
using namespace std;

class mstack
{
public:
    int data;
    mstack *next;
    mstack(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    void push(mstack *&top, int d)
    {
        mstack *n = new mstack(d);

        if (top == NULL)
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }
    int pop(mstack * &top)
    {
        
        if (top == NULL)
        {
            return -1;
        }
        int d = top->data;
        mstack *to = top;
        top = top->next;
        delete (to);
        return d;
    }

    void print(mstack *&top)
    {
        mstack *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};




int main()
{
    ifstream m;
    m.open("input.txt");
    mstack *s = NULL;

    int n=1;
    while(n>=0)
    {
        m>>n;
        if(n>=0)
        s->push(s,n);
    }

    mstack* temp=s;

    int c=0;
    while(temp!=NULL)
    {
        c++;
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    if(c!=5)
    {
        cout<<"error\n";
    }
    cout<<"\n";
    while(!m.eof())
    {
        m>>n;
        s->push(s,n);
    }
    s->print(s);



}
