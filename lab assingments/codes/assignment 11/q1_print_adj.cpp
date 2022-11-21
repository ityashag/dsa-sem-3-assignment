#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    void push(node *&head, int d)
    {
        node *n = new node;
        n->data = d;
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
    }

    void print(node *q)
    {
        node *n = q;
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    int v;
    cout << "enter the number of vertices : ";
    cin >> v;

    int e;
    cout << "enter the number of edges : ";
    cin >> e;

    node **head = new node *[v];

    for (int i = 0; i < v; i++)
    {
        head[i] = NULL;
    }

    for (int i = 0; i < e; i++)
    {
        cout << "enter the edge (a<->b) : ";
        int a, b;
        cin >> a >> b;
        head[a]->push(head[a], b);
        head[b]->push(head[b], a);
    }

    cout << "ADJ LIST: \n";

    for (int i = 0; i < v; i++)
    {
        cout << i << " : ";
        head[i]->print(head[i]);
    }
}
