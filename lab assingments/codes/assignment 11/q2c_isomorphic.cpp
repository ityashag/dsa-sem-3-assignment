#include<iostream>
using namespace std;
class node
{
    public:
    node* next;
    int data;

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
            node* t=h;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=n;
        }
    }

};

int main()
{
    int v1;
    cout<<"enter the number of nodes of graph 1 : ";
    cin>>v1;

    int e1;
    cout<<"enter the number of edges of graph 1 : ";
    cin>>e1;

    node ** head1= new node *[v1];
     int in1[v1];

    for(int i=0;i<v1;i++)
    {
        head1[i]=NULL;
        in1[i]=0;
    }
   


    for(int i=0;i<e1;i++)
    {
        cout<<"enter the edge (a->b) : " ;
        int a,b;
        cin>>a>>b;
        head1[a]->push(head1[a],b);
        in1[b]++;
    }

    for(int i=0;i<v1-1;i++)
    {
        for(int j=1;j<v1;j++ )
        {
            if(in1[j]<in1[i])
            {
                int t=in1[j];
                in1[j]=in1[i];
                in1[i]=t;
            }
        }
    }



    int v2;
    cout<<"enter the number of nodes of graph 1 : ";
    cin>>v2;

    int e2;
    cout<<"enter the number of edges of graph 1 : ";
    cin>>e2;

    node ** head2= new node *[v2];
     int in2[v2];

    for(int i=0;i<v2;i++)
    {
        head2[i]=NULL;
        in2[i]=0;
    }
   


    for(int i=0;i<e2;i++)
    {
        cout<<"enter the edge (a->b) : " ;
        int a,b;
        cin>>a>>b;
        head2[a]->push(head2[a],b);
        in2[b]++;
    }

    for(int i=0;i<v2-1;i++)
    {
        for(int j=1;j<v2;j++ )
        {
            if(in2[j]<in2[i])
            {
                int t=in2[j];
                in2[j]=in2[i];
                in2[i]=t;
            }
        }
    }


    if(v1==v2 && e1==e2)
    {
        for(int i=0;i<v1;i++)
        {
            if(in1[i]!=in2[i])
            {
                cout<<"non isomorphic .\n";
                return 0;
            }

        }
        cout<<"isomorphic .\n";

    }
    else
    {
        cout<<"non isomorphic \n";

    }
}