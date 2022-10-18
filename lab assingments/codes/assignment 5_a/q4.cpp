#include<iostream>
using namespace std;

class node{
    public:
    int coff;
    int pow;
    node * next;

    node(int c,int p)
    {
        this->coff=c;
        this->pow=p;
        this->next=NULL;
    }

    void create (node * & head,int c,int p)
    {


        node * n=new node (c,p);

        if(head==NULL)
        {
            head=n;
            return;
        }
        node * temp=head;
        while(temp->next!=NULL) temp=temp->next;

        temp->next=n;
    }


    void print(node * & head)
    {
        node* temp=head;
        cout<<temp->coff<<" x^"<<temp->pow;
        temp=temp->next;
        while(temp!=NULL)
        {
            cout<<" + "<<temp->coff<<" x^"<<temp->pow;
            temp=temp->next;
        }
      
    }

    node* multiply(node*&p1,node*&p2)
    {
        node* ans=NULL;

        node* i=p1;
        while(i!=NULL)
        {
            node*j=p2;
            while(j!=NULL)
            {
                ans->create(ans,i->coff*j->coff,i->pow+j->pow);
                j=j->next;


            }
            i=i->next;
        }

        return ans;
    }


    // sort in decreasing order 
    void sort(node * & head)
    {
        node* i=head;
        while(i!=NULL)
        {
            node * j=i;
            int tc=i->coff;
            int tp=i->pow;
            node* max=i;

            while(j!=NULL)
            {
                if(j->pow> max->pow) max=j;
                j=j->next;

            }

            i->coff=max->coff;
            i->pow=max->pow;
            max->coff=tc;
            max->pow=tp;
            i=i->next;
        }
    }

};

int main()
{
    node* p1=NULL;
    int n1;
    cout<<"enter the length of polynomial 1 : ";
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        int c;
        cout<<"enter the coefficient ";
        cin>>c;
        int p;
        cout<<"enter the power of x : ";
        cin>>p;
        p1->create(p1,c,p);
    }
   

    node* p2=NULL;
    int n2;
    cout<<"enter the length of polynomial 2 : ";
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        int c;
        cout<<"enter the coefficient ";
        cin>>c;
        int p;
        cout<<"enter the power of x : ";
        cin>>p;
        p2->create(p2,c,p);
    }
    cout<<"( ";
    p1->print(p1);
    cout<<" )*(";
    p2->print(p2);
    cout<<") = ";

    node * m= p1->multiply(p1,p2);
    m->sort(m);
    m->print(m);
    cout<<"\n= ";
    node* i=m;
    while(  i!=NULL && i->next!=NULL )
    {
        node*j=i;
        if(i->next!=NULL)j=j->next;
        int c=0;
        while(j!=NULL && i->pow==j->pow)
        {
            c+=j->coff;
            j=j->next;
        }
        i->coff+=c;
        if(c!=0)
        i->next=j;

        i=i->next;
    }
    m->print(m);

}
