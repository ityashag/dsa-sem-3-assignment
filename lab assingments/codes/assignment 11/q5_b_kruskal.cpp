#include<iostream>
#include<algorithm>
using namespace std;
bool cmp (int a[],int b[])
{
    return a[2]<b[2];
}
void make_set(int parent [],int rank [],int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
int findparent(int parent[],int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    return findparent(parent,parent[node]);
}
void unionset(int u,int v,int parent[],int rank[])
{
    
    u=findparent(parent,u);
    v=findparent(parent,v);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[u]=v;
        rank[u]++;
    }
}

int min_spanning_tree(int ** edges, int n,int e)
{
    sort(edges,edges+e,cmp);
    //for(int i=0;i<e;i++)
    // {
    //    cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<"\n";
    //}
    int rank[n];
    int parent[n];
    make_set(parent,rank,n);
    int min_wt=0;
   // for(int i=0;i<n;i++) cout<<parent[i]<<" "<<rank[i]<<"\n";
    for(int i=0;i<e;i++)
    {
        
        int u=findparent(parent,edges[i][0]);
        int v=findparent(parent,edges[i][1]);

        int wt=edges[i][2];
        if(u!=v)
        {
            unionset(u,v,parent,rank);
            min_wt+=wt;
        }
       // cout<<parent[u]<<" "<<rank[u]<<"\n";
       // cout<<parent[v]<<" "<<rank[v]<<"\n";
       // cout<<"cost : "<<min_wt<<"\n";
    }
    return min_wt;


}
int main()
{
     int n;
    cout<<"enter the number of node : ";
    cin>>n;
    int e;
    cout<<"enter the number of edges : ";
    cin>>e;
    
   

    int ** edges = new int * [e];
    for(int i=0;i<e;i++) {edges[i]=new int [3]; }
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cout<<"enter the edge a - b  and weight: ";
        cin>>a>>b>>w;
        edges[i][0]=a;
        edges[i][1]=b;
        edges[i][2]=w;
    }

    int cost = min_spanning_tree(edges,n+1,e);
    cout<<"\nthe min spanning tree cost : "<<cost;


    
}
// 7 9 1 2 28 2 3 16 3 4 12 4 5 22 5 6 25 6 1 10 2 7 14 7 5 24 7 4 18
// 6 8 1 2 1 2 3 3 1 3 2 3 4 4 4 5 7 3 5 5 3 6 6 6 5 8