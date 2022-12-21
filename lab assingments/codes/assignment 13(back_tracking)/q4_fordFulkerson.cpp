#include<iostream>
using namespace std;

class queue
{
    public:
    int data;
    queue * next;
    queue(int d)
    {
        this->data=d;
        this->next=NULL;
    }
    void push(queue * & q,int d)
    {
        queue * n = new queue (d);
        if(q==NULL)
        {
            q=n;
        }
        else{
            queue * t= q;
            while(t->next !=  NULL)
            {
                 t=t->next;
            }
            t->next=n;
        }
        
    }

    void pop(queue * &q)
    {
        if(q!=NULL)
        {
            queue * d = q;
            q=q->next;
            delete d;
        }
    }

    int top(queue * & q)
    {
        if(q!=NULL)
        {
            return q->data;
        }
        return 0;
    }
    bool isempty(queue * & q)
    {
        return q==NULL ? true : false;
    }
};

bool bfs(int ** rmat , int s,int t,int parent[],int n)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;

        queue * q=NULL;
        q->push(q,s);
        visited[s]=1;
        parent[s]=-1;

        while(!q->isempty(q))
        {
            int u = q->top(q);
            q->pop(q);

            for(int i=0;i<n;i++)
            {
                if(visited[i]==false && rmat[u][i]>0)
                {
                    if(i==t)
                    {
                        parent[i]=u;
                        return true;
                    }
                    q->push(q,i);
                    parent[i]=u;
                    visited[i]=true;
                }
            }

        }

    }
    return false;
}

int fordFulkerson(int ** mat,int s,int t,int n)
{
    int u, v;
    
    int ** rmat = new int * [n];
    for(int i=0;i<n;i++) rmat[i]=new int [n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            rmat[i][j]=mat[i][j];
        }
    }
 
    int parent[n];
    int max_flow = 0;
    while (bfs(rmat, s, t, parent,n)) {
        int path_flow = 1000000;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rmat[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rmat[u][v] -= path_flow;
            rmat[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}


int main()
{
    int n;
    cout<<"enter the number of vertices : ";
    cin>>n;

    int ** mat = new int *[n];
    for(int i=0;i<n;i++) mat[i]=new int[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=0;
        }
    }
    int e;
    cout<<"enter number of edges : ";
    cin>>e;


    for(int i=0;i<e;i++)
    {
        cout<<"enter the a -> b  and capacity ";
        int a,b,c;
        cin>>a>>b>>c;
        mat[a][b]=c;
    }
    int s,t;
    cout<<"\nenter the starting and target point : ";
    cin>>s>>t;
    int m = fordFulkerson(mat,s,t,n);

    int a ,b;
    cout<<"\nenter the add capacity edge  a ->b ";
    cin>>a>>b;
    mat[a][b]++;

    cout<<"\nthe new flow (after add capacity) : "<<fordFulkerson(mat,s,t,n);

    cout<<"\nenter the reduce capacity edge  a ->b ";
    cin>>a>>b;
    mat[a][b]--;
    cout<<"\nthe new flow (after reduce capacity) : "<<fordFulkerson(mat,s,t,n);



}

// 6 10 0 1 16 0 2 13 1 3 12 1 2 10 2 1 4 2 4 14 3 2 9 4 3 7 3 5 20 4 5 4 0 5