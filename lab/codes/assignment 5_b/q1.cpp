#include <iostream>
#include <stack>
using namespace std;

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

    int s(queue *&f)
    {
        queue *i = f;
        int c = 0;
        while (i != NULL)
        {
            c++;
            i = i->next;
        }
        return c;
    }

    void solve(queue *&f, queue *&r)
    {
        int fs = f->data;
        int ls = r->data;
        stack<int> a;
        stack<int> b;
        int c = 1;
        int n = f->s(f);
        queue *temp = f;
        f->dequeue(f, r);
        if (f->s(f) % 2 != 0)
        {
            while (c < ((n) / 2) - 1)
            {
                a.push(f->data);

                f->dequeue(f, r);
                c++;
            }
        }
        else
        {
            while (c < ((n) / 2))
            {
                a.push(f->data);

                f->dequeue(f, r);
                c++;
            }
        }

        while (c < n - 1)
        {
            b.push(f->data);

            f->dequeue(f, r);
            c++;
        }

        f->dequeue(f, r);

        f->enqueue(f, r, fs);
        while (!a.empty() || !b.empty())
        {
            if (!b.empty())
            {
                f->enqueue(f, r, b.top());
                b.pop();
            }
            if (!a.empty())
            {
                f->enqueue(f, r, a.top());
                a.pop();
            }
        }
        f->enqueue(f, r, ls);
    }
};

int main()
{
    queue *f = NULL;
    queue *r = NULL;

    int n;
    cout << "enter the length link list : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c;
        cout << "enter the data : ";
        cin >> c;
        f->enqueue(f, r, c);
    }
    f->print(f);
    f->solve(f, r);
    f->print(f);
}
