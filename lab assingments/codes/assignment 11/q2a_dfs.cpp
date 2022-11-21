#include<iostream>
using namespace std;

class node
{
    public :
    int data;
    node * next;

    void push(node * & h,int d)
    {
        node * n=new node;
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
};

void dfs(int u,int visited[],node ** head)
{
    visited[u]=1;
    cout<<u<<" ";

    node * t=head[u];

    while(t!=NULL)
    {
        if(!visited[t->data])
        {
            dfs(t->data,visited,head);
        }
        t=t->next;
    }
}

int main()
{
    int v;
    cout<<"enter the number of vertices : ";
    cin>>v;

    int e;
    cout<<"enter the numbr of edges : ";
    cin>>e;

    node ** head = new node * [v];
    int visited[v];

    for(int i=0;i<v;i++)
    {
        head[i]=NULL;
        visited[i]=0;
    }

    for(int i=0;i<e;i++)
    {
        int a,b;
        cout<<"enter the edge (a<->b) : ";
        cin>>a>>b;

        head[a]->push(head[a],b);
        head[b]->push(head[b],a);
    }

    cout<<"dfs traversal : \n";


    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,head);

        }
    }

}