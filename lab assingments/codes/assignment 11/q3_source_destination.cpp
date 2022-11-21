#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

class queue
{
public:
    queue *next;
    int data;
    queue(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    void push(queue *&h, int d)
    {
        queue *n = new queue(d);
        if (h == NULL)
        {
            h = n;
        }
        else
        {
            queue *t = h;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
    }

    void pop(queue *&h)
    {
        if (h != NULL)
        {
            queue *t = h;
            h = h->next;
            delete t;
        }
    }

    int top(queue *&h)
    {
        if (h != NULL)
        {
            return h->data;
        }
        return 0;
    }
    bool isempty(queue *&q)
    {
        return q == NULL ? true : false;
    }
};

class node
{
public:
    node *next;
    int data;

    void push(node *&h, int d)
    {
        node *n = new node;
        n->next = NULL;
        n->data = d;
        if (h == NULL)
        {
            h = n;
        }
        else
        {
            node *t = h;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
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

    int parent[v];
    int visited[v];
    node **head = new node *[v];

    for (int i = 0; i < v; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
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

    int s, d;
    cout << "enter source and destination : ";
    cin >> s >> d;
    int number_of_path=0;

    queue *q = NULL;
    q->push(q, s);
    while (!q->isempty(q))
    {
        int t = q->top(q);
        cout<<t<<endl;
        q->pop(q);
        // if(t!=d){
        visited[t] = 1;
        if(t==d)
        {
            break;
        }
        // }
        // else
        // {
        //     number_of_path++;
        //     continue;
        // }
        node *l = head[t];
        while (l != NULL)
        {
            if (!visited[l->data])
            {
                parent[l->data] = t;
                q->push(q, l->data);
            }
            l = l->next;
        }
    }
    int c = 0;
    int dd = d;

    while (dd != -1 && dd != s)
    {
        c++;
        dd = parent[dd];
    }
  //  cout<<dd;
    if (dd == s)
    {
        dd = d;
        while (dd != -1 && dd != s)
        {
            cout<<dd<<" <- ";
            dd = parent[dd];
        }
        cout<<s<<"\npath lenght = "<<c;
        cout<<"\nnumber of paths : "<<number_of_path;
    }
    else
    {
        cout<<"cannot reach from source to destination ";
    }
}

// 8 9 0 1 0 4 0 5 1 2 2 3 4 3 5 6 6 7 7 3 0 3