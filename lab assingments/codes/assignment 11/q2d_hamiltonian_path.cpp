#include<iostream>
using namespace std;

class node 
{
    public:
    node * next;
    int data;
    void push(node * & h,int d)
    {
        node * n =new node;
        n->data=d;
        n->next=NULL;

        if(h==NULL)
        {
            h=n;
        }
        else
        {
            node * t=h;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=n;
        }
    }
    void pop(node * & h)
    {
        if(h!=NULL)
        {
            if(h->next==NULL)
            {
                h=NULL;
                return;
            }
            node * t=h;
            while(t->next->next!=NULL)
            {
                t=t->next;
            }
            node* to = t->next;
            t->next=NULL;
            delete to;
        }

    }

    int size(node * h)
    {
        int c=0;

        node * t=h;
        while(t!=NULL)
        {
            c++;
            t=t->next;
        }
        return c;

    }

};

bool path(int u,int v,int visited[], node * p ,node ** head)
{
    visited[u]=1;
    p->push(p,u);
    if(p->size(p)==v)
    {
        cout<<"HAMILTONIAN PATH : ";
        node * t=p;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;

        }
        return true;
    }

    node * t =head[u];
    while(t!=NULL)
    {
        if(!visited[t->data])
        {
            if(path(t->data,v,visited,p,head)) return true;
        }
        t=t->next;
    }

    visited[u]=0;
    p->pop(p);
    return false;

}

int main()
{
    int v;
    cout<<"enter the number of vertices : ";
    cin>>v;
    int e;
    cout<<"enter the number of edges : ";
    cin>>e;

    node ** head = new node * [v];
    int visited[v];

    for(int i=0;i<v;i++){

     head[i]=NULL;
     visited[i]=0;
    }

    for(int i=0;i<e;i++)
    {
        cout<<"enter edge (a<->b) : ";
        int a,b;
        cin>>a>>b;
        head[a]->push(head[a],b);
        head[b]->push(head[b],a);
    }


    node * p=NULL;
    bool k=false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(path(i,v,visited,p,head)) k=true;

        }
    }

    if(!k)
    {
        cout<<"no hamiltonian path . ";
    }



}