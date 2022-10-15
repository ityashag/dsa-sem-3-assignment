#include<iostream>
using namespace std;


template<typename t>
class stack
{
    public:
    t data;
    stack<t> * next;

    stack(t d)
    {
        this->data=d;
        this->next=NULL;
    }

    void push(stack<t> * & s,t d)
    {
        stack<t> * n=new stack (d);
        if(s==NULL)
        {
            s=n;
            //return;
        }
        else
        {
            n->next=s;
            s=n;
            //return;
        }
    }

    void pop(stack<t> * & s)
    {
        if(s!=NULL)
        {
            stack<t> * to_del=s;
            s=s->next;
            delete to_del;
        }
    }
    t top(stack<t> * & s)
    {
        if(s!=NULL)
        {
            return s->data;
        }
        return -1;
    }

    bool isempty(stack<t> * & s)
    {
        return s==NULL ? true : false;
    }

    void insert_at_bottom(stack<t>* &s,t d)
    {
        if(s==NULL)
        {
            s->push(s,d);
            return;

        }

        t data=s->top(s);
        s->pop(s);
        s->insert_at_bottom(s,d);
        s->push(s,data);
    }
    void print(stack<t> * s)
    {
        stack<t> * te=s;
        while(te!=NULL)
        {
            cout<<te->data<<" ()"<<endl;
            te=te->next;
        }
    }



};



//template<typename t>
class queue
{
    public:
    stack<int> * s1;
    queue()
    {
        s1=NULL;
    }
    void push(int  d)
    {
       s1->insert_at_bottom(s1,d);
    }

    

    void pop()
    {
        s1->pop(s1);
        
    }
    int  front()
    {
        return s1->top(s1);
    }

    bool isempty()
    {
        return s1->isempty(s1);
        
    }



};

int main()
{
    queue q;
    q.push(7);
    q.push(74);
    q.push(6);
    q.push(75);
    while(!q.isempty())
    {
        cout<<q.front()<<"\n";
        q.pop();

    }
}

