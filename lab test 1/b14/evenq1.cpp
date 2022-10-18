#include<iostream>
using namespace std;

template<typename t>
class queue
{
    public:
    t data;
    queue * next;

    queue(t d)
    {
        this->data=d;
        this->next=NULL;
    }

    void push(queue<t> *&s,t d)
    {
        queue<t> * n=new queue<t> (d);
        if(s==NULL)
        {
            s=n;
        }
        else
        {
            queue<t> * temp=s;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;

        }

    }

    void pop(queue<t> *&s)
    {

        if(s!=NULL)
        {
            queue<t> * to=s;

            s=s->next;
            delete to;

        }
    }
    t top(queue<t> * &s)
    {
        if(s!=NULL)
        {
            return s->data;
        }
        return -1;
    }
    int size(queue<t> *s)
    {
        int c=0;
         queue<t> * temp=s;
            while(temp!=NULL)
            {
                c++;
                temp=temp->next;
            }
            return c;

    }

    bool isempty(queue<t>* s)
    {
        return s==NULL ? true: false;
    }
};

class stack
{

    public:
    queue<int> * q;
    stack()
    {
        q=NULL;
    }
    void push(stack s,int d)
    {
        q->push(q,d);
        for(int i=0;i<q->size(q)-1;i++)
        {
            int t=q->top(q);
            q->pop(q);
            q->push(q,t);
        }

    }
    void pop()
    {
        q->pop(q);
    }

    int top()
    {
        return q->top(q);
    }
    bool isempty()
    {
        return q->isempty(q);
    }



};

int main()
{
    stack s;

    for(int i=0;i<10;i++)
    {
        s.push(s,i+1);
    }

    while(!s.isempty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }


}