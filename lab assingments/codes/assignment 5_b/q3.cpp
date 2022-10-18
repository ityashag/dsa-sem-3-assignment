#include <iostream>
#include <stack>
using namespace std;

class queue
{
public:
    string data;
    queue *next;

    queue(string d)
    {
        this->data = d;
        this->next = NULL;
    }
    void enqueue(queue *&f, queue *&r, string d)
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

    void bubbleSort(queue *&f)
    {
        queue *i = f;
        while (i != NULL)
        {
            queue *j = i;
            string temp = i->data;
            queue *miin = i;
            while (j != NULL)
            {
                if (j->data < miin->data)
                    miin = j;
                j = j->next;
            }
            i->data = miin->data;
            miin->data = temp;
            i = i->next;
        }
    }
    queue *rev(queue *&f)
    {
        if (f == NULL || f->next == NULL)
        {
            return f;
        }
        queue *ch = rev(f->next);
        f->next->next = f;
        f->next = NULL;
        return ch;
    }
};

int main()
{
    queue *f = NULL;
    queue *r = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string ss;
        cout << "enter data : ";
        cin >> ss;
        f->enqueue(f, r, ss);
    }
    f->print(f);
    f->bubbleSort(f);
    f->print(f);
    f = f->rev(f);
    f->print(f);
}
