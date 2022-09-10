#include <bits/stdc++.h>
using namespace std;

class mstack
{
public:
    int data;
    mstack *next;
    static int mi;
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
        mi = min(mi, d);

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

    int min_element()
    {
        return mi;
    }
};

int mstack ::mi = INT_MAX;

int main()
{
    mstack *s = NULL;

    int n;
    cout << "enter the length of stack : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s->push(s);
    }
    cout << "STACK : TOP->";

    s->print(s);

    cout << "\n"
         << "the min element in stack : " << s->mi;
}
