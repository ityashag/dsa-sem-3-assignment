#include <iostream>
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

    void push(queue *&q, int d)
    {
        queue *n = new queue(d);
        if (q == NULL)
        {
            q = n;
        }
        else
        {
            queue *t = q;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
    }
    void pop(queue *&q)
    {
        if (q != NULL)
        {
            queue *t = q;
            q = q->next;
            delete t;
            return;
        }
    }
    int top(queue *q)
    {
        if (q != NULL)
        {
            return q->data;
        }
        return 0;
    }
    bool isempty(queue *q)
    {
        return q == NULL ? true : false;
    }
};

class node
{
public:
    int data;
    node *next;

    void push(node *&q, int d)
    {
        node *n = new node ;
        n->data=d;
        n->next=NULL;
        if (q == NULL)
        {
            q = n;
        }
        else
        {
            node *t = q;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
    }

};


void bfs(int i,int visited[],node ** head)
{
    queue * q=NULL;
    q->push(q,i);
    while(!q->isempty(q))
    {
        int top=q->top(q);
        q->pop(q);
        cout<<top<<" ";
        visited[top]=1;
        node * n=head[top];
        while(n!=NULL)
        {
            if(!visited[n->data])
            {
                q->push(q,n->data);
            }
            n=n->next;
        }
    }
}

int main()
{
    // queue * q=NULL;
    // for(int i=0;i<10;i++)
    // {
    //     q->push(q,i+1);
    // }
    // while(!q->isempty(q))
    // {
    //     cout<<q->top(q)<<" ";
    //     q->pop(q);
    // }

    int v;
    cout<<"enter the number vertices : ";
    cin>>v;

    int e;
    cout<<"enter the number of edges : ";
    cin>>e;

    node ** head =new node * [v];
    int visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        head[i]=NULL;
    }

    for(int i=0;i<e;i++)
    {
        cout<<"enter the edge (a<->b) : ";
        int a,b;
        cin>>a>>b;
        head[a]->push(head[a],b);
        head[b]->push(head[b],a);
    }

    cout<<"BFS TRAVERSAL : \n";
    int k=1;
    cout<<"subgraph "<<k++<<" : ";
    bfs(0,visited,head);
    for(int i=1;i<v;i++)
    {
        if(!visited[i])
        {
            cout<<"\nsubgraph "<<k++<<" : ";
            bfs(i,visited,head);
        }

    }
    
}