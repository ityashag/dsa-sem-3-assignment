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

int main()
{
    int n;
    cout<<"enter the number of vertices : ";
    cin>>n;

    int mat[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=0;
        }
    }

    int e;
    cout<<"enter the  number of edges : ";
    cin>>e;

    for(int i=0;i<e;i++)
    {
        int a,b;
        cout<<"enter edge from a - b ";
        cin>>a>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }
    int color[n];
    int visited[n];
    int max_color=1;
    for(int i=0;i<n;i++)
    {
        color[i]=1;
        visited[i]=0;
    }
    int m;
    cout<<"enter the number of colors : ";
    cin>>m;

    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;

        visited[i]=1;
        queue * q=NULL;
        q->push(q,i);
        while(q->isempty(q))
        {
            int top = q->top(q);
            q->pop(q);
            for(int j=0;j<n;j++)
            {
                if(mat[top][j])
                {
                    if(color[top]==color[j])
                    {
                        color[j]++;
                    }
                    max_color=max(max_color,max (color[top],color[i]));
                    if(max_color>m)
                    {
                        cout<<"\nnot possible to paint with m colors . ";
                        return 0;
                    }
                    if(!visited[j])
                    {
                        visited[j]=true;
                        q->push(q,j);
                    }
                }

            }

        }

    }
    cout<<"\ngraph can be painted with "<<m<<" colors . ";
}

// 4 5 0 1 1 2 2 3 3 0 0 2 3