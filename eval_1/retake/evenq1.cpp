#include<iostream>

using namespace std;


class node
{
    public: 
    int data;
    node * next;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

    void insert(node * & s,int d)
    {
        node * n=new node(d);

        if(s==NULL)
        {
            s=n;
            return;
        }
        else
        {
            node * temp=s;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=n;
        }
    }

    int solve(node * n1, node * n2,int k)
    {
        int c=0;
        node* t1=n1;
        while(t1)
        {
            node* t2=n2;

            while(t2)
            {
                if(t1->data * t2->data==k)
                {
                    c++;
                    cout<<"( "<<t1->data<<" , "<<t2->data<<" ) ";
                }
                t2=t2->next;
            }
            t1=t1->next;

        }

        return c;
    }

};

int main()
{
    node * n1=NULL;
    node* n2=NULL;

    int n;
    int m;
    cout<<"enter the length of link list 1 : ";
    cin>>n;
    cout<<"enter all elements of link list 1 : ";


    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        n1->insert(n1,d);

    }

    cout<<"enter the length of link list 2 : ";
    cin>>m;
    cout<<"enter all elements of link list 2 : ";


    for(int i=0;i<m;i++)
    {
        int d;
        cin>>d;
        n2->insert(n2,d);

    }

    int k;
    cout<<"enter the value of key : ";
    cin>>k;
    cout<<"\n pair : ";
    int ans=n1->solve(n1,n2,k);

    cout<<"\n number of pairs are : "<<ans;

}