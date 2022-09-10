#include <iostream>
#include <stack>
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

    void solve(mstack *&top)
    {
        int min = 1000;
        mstack *top2 = NULL;
        int d = top->pop(top);
        if (d < min)
        {
            if (min != 1000)
            {

                top2->push(top2, min);
                min = d;
            }
            else
            {
                min = d;
            }
        }
        else
        {
            top2->push(top2, d);
        }
        d = top->pop(top);

        while (d != -1)
        {
            
            if (d < min)
            {
                if (min != 1000)
                {

                    top2->push(top2, min);
                    min = d;
                }
                else 
                {
                    min = d;
                }
            }
            else
            {
                top2->push(top2, d);
            }

            d = top->pop(top);
        }
        //top2->print(top2);

        d=top2->pop(top2);
        while(d!=-1)
        {
            top->push(top,d);
            d=top2->pop(top2);
        }
        top->push(top,min);
    }
};

class queue
{
public:
    int data;
    queue *next;

    queue(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    void enqueue(queue *&f, queue *&r, int d)
    {

        queue *n = new queue(d);
        if (f == NULL)
        {
            f = r = n;
            return;
        }
        r->next = n;
        r = n;
    }
    void dequeue(queue *&f, queue *&r)
    {
        if (f == NULL)
        {
            cout << "underflow";
            return;
        }
        queue *to = f;
        f = f->next;
        delete (to);
    }

    void print(queue *&f)
    {
        queue *temp = f;
        while (temp != NULL)
        {

            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int s(queue *&f)
    {
        int c = 0;
        queue *temp = f;
        while (temp != NULL)
        {

            c++;
            temp = temp->next;
        }
        return c;
    }

    void solve(queue *& f,queue *&r)
    {
        int min=100;
        queue * rr=r;
        while(f!=rr)
        {
            int d=f->data;
            f->dequeue(f,r);

            if(d<min)
            {
                if(min==100)
                {
                    min=d;
                }
                else
                {
                    
                    f->enqueue(f,r,min);
                    min=d;
                }
            }
            else
            {
                f->enqueue(f,r,d);

            }
        }
        f->enqueue(f,r,min);
        rr=r;
        while(f!=rr)
        {
            f->enqueue(f,r,f->data);
            f->dequeue(f,r);
        }
        

    }
};

int main()
{
    queue *f = NULL;
    queue *r = NULL;

    int n;
    cout << "enter the length queue: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c;
        cout << "enter the data : ";
        cin >> c;
        f->enqueue(f, r, c);
    }
    f->print(f);
    f->solve(f,r);
    f->print(f);


    mstack *s = NULL;

    int n1;
    cout << "enter the length stack ";
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int c;
        cout << "enter the data : ";
        cin >> c;
        s->push(s,c);
    }
    cout<<"initial stack : ";
    s->print(s);
    s->solve(s);
    cout<<"\nfinal stack : ";
    s->print(s);
}
