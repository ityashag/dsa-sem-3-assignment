#include<iostream>
using namespace std;

class node 
{
    public:
    node * next;
    int data;

    void push(node * &h,int d)
    {
        node * n = new node;
        n->next=NULL;
        n->data=d;
        if(h==NULL)
        {
            h=n;
        }
        else
        {
            node * t= h;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=n;
        }
    }

};

 void solve(int u,bool & c,int visited[],int parent[],node ** adj)
  {
      
      visited[u]=1;
      
      node * t=adj[u];
      while(t!=NULL)
      {
          if(!visited[t->data])
          {
              parent[t->data]=u;
              solve(t->data,c,visited,parent,adj);
              
          }
          else
          {
              if(parent[u]!=t->data)
              {
                  c=true;
                  return;
              }
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
    cout<<"enter the number of edges : ";
    cin>>e;

    int parent[v];
    int visited[v];
    node ** head= new node *[v];

    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
        visited[i]=0;
        head[i]=NULL;
    }

    for(int i=0;i<e;i++)
    {
        cout<<"enter the edge (a<->b) : " ;
        int a,b;
        cin>>a>>b;
        head[a]->push(head[a],b);
        head[b]->push(head[b],a);
    }

    bool k=false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            solve(i,k,visited,parent,head);

        }

    }

    if(k)
    {
        cout<<"cycle is present";
    }
    else cout<<"cycle is not present";
}
