#include <iostream>
#include <limits.h>
using namespace std;

class node
{
public:
    int n;
    int w;
    node *next;

    void insert(node *&head, int d, int w)
    {
        node *ne = new node;
        ne->n = d;
        ne->w = w;
        ne->next = NULL;
        if (head == NULL)
        {
            head = ne;
        }
        else
        {
            node *t = head;
            while (t->next != NULL)
                t = t->next;
            t->next = ne;
        }
    }
};

void dfs(node **head, int nd, int cost, int ct, int &ans, int visited[], int n)
{
    if (ct >= n)
        return;
    if (nd != 0)
    {
        visited[nd] = 1;
    }

    node *t = head[nd];

    while (t)
    {
        if (t->n == 0)
        {
            if (ct == n - 1)
            {
                ans = min(ans, cost + t->w);
            }
        }
        else if(!visited[t->n])
        {
            dfs(head, t->n, cost + t->w, ct+1, ans, visited, n);
        }

        t = t->next;
    }
    visited[nd] = 0;
}

int main()
{
    int n;
    cout << "enter the number of nodes : ";
    cin >> n;

    int e;
    cout << "enter the number of edges : ";
    cin >> e;

    node **head = new node *[n];

    for (int i = 0; i < n; i++)
    {
        head[i] = NULL;
    }

    for (int i = 0; i < e; i++)
    {
        cout << "enter the edge a-b and weight";
        int a, b, w;
        cin >> a >> b >> w;
        head[a]->insert(head[a], b, w);
        head[b]->insert(head[b], a, w);
    }
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int a = INT_MAX;
  
    dfs(head, 0, 0, 0, a, visited, n);

    cout<<"\ncost : "<<a;
}

// 8 16 0 1 4 1 7 1 7 6 7 6 0 6 0 3 5 0 2 4 1 2 6 1 4 3 7 4 2 7 5 4 6 5 3 6 3 2 3 2 1 2 4 2 4 5 2 5 3 5