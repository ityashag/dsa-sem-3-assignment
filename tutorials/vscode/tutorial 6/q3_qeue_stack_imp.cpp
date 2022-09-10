#include <iostream>
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
    void push(mstack *&top)
    {
        int d;
        cout << "enter the data : ";
        cin >> d;
        mstack *n = new mstack(d);

        if (top == NULL)
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }
    int pop(mstack *&top)
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
    void enqueue(queue *&f, queue *&r)
    {
        int d;
        cout << "enter the data ";
        cin >> d;

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
            cout << "underflow queue \n";
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
};

int main()
{
    queue *f = NULL;
    queue *r = NULL;
    mstack *s = NULL;

    int t = 1;
    while (t)
    {

        cout << "enter 1 to push in stack\nenter 2 to pop in stack\nenter 3 to print stack\nenter 4 to enqueue \nenter 5 to dequeue\nenter 6 to print queue\n enter 0 to exit\nenter your choise: ";
        cin >> t;

        switch (t)
        {
        case 0:
            break;
        case 1:
            s->push(s);
            break;
        case 2:
            cout << "pop item : " << s->pop(s) << "\n";
            break;
        case 3:
            cout << "STACK : top->";
            s->print(s);
            cout << "\n";
            break;
        case 4:
            f->enqueue(f, r);
            break;
        case 5:
            f->dequeue(f, r);
            break;

        case 6:
            cout << "STACK : front->";
            f->print(f);
            cout << "<-rear\n";
        }
    }
}
