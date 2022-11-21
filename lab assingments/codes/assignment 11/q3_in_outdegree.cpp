#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    void push(node *&h, int d)
    {
        node *n = new node;
        n->data = d;
        n->next = NULL;
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

    int size(node * & h)
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

int main()
{
    int v;
    cout<<"enter the vertices : ";
    cin>>v;

    int e;
    cout<<"enter the edges : ";
    cin>>e;

    node ** head =new node  * [v];
    int in[v];
    int out[v];

    for(int i=0;i<v;i++)
    {
        in[i]=0;
        out[i]=0;
        head[i]=NULL;
    }

    for(int i=0;i<e;i++)
    {
        int a,b;
        cout<<"enter edges a<->b : ";
        cin>>a>>b;
        head[a]->push(head[a],b);
        head[b]->push(head[b],a);
    }

    for(int  i=0;i<v;i++)
    {
        out[i]=head[i]->size(head[i]);
        node * t=head[i];
        while(t!=NULL)
        {
            in[t->data]++;
            t=t->next;
        }
    }

    for(int i=0;i<v;i++)
    {
        cout<<i<<" out degree : "<<out[i]<<" in degree : "<<in[i]<<endl;
    }
    int k=0;
    for(int i=0;i<v;i++)
    {
        if(in[k]<in[i]) i=k;
    }

    cout<<"max inorder degree of the node : "<<k;
    cout<<endl;
    int nd;
    cout<<"enter the node whoes indegree has to be find : ";
    cin>>nd;

    cout<<"indegee of "<<nd<<" is : "<<in[nd];
}