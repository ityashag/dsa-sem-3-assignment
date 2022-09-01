#include<iostream>
using namespace std;

template<typename t>
class node{
    public:
    t data;
    node * next;
    node(t d)
    {
        this->data=d;
        this->next=NULL;
    }

    void create(node <t>* &head,int v)
    {
        
        node<t> * n=new node<t>(v);
        if(head==NULL)
        {
            head=n;
            return;
        }

        node<t> * temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=n;
    }

    void delete_first_node(node<t> * &head)
    {
        if(head==NULL || head->next == NULL)
        {
            head=NULL;
            return;
        }
        else
        {
            node<t> * temp=head;
            head=head->next;
            temp->next=NULL;
            delete(temp);
        }
        
    }

    void delete_last_node(node<t> * &head)
    {
        
        node<t> * temp=head;
        if(temp->next==NULL)
        {
            head=NULL;
            return;
        }

        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        node<t> * to_del=temp->next;

        temp->next=NULL;
        delete(to_del);
    }

    void print(node <t>* &head)
    {

        node <t>* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }

        cout<<"NULL\n";

    }

    int sum(node<t> *&head)
    {
        node<int> *i = head;
        int sum=0;
        while (i != NULL)
        {
            sum+=i->data;
            i=i->next;

        }
        return sum;
    }

    int last_node(node<t> *&head)
    {
        node<int> *i = head;
        while (i->next != NULL)
        {
            i=i->next;
        }
        return i->data;

    }
};


int main()
{
    node <int> * ll1=NULL;
    int n;
    cout<<"enter the length of link list : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int  v;
        cout<<"enter the value : ";
        cin>>v;
        ll1->create(ll1,v);
    }

    node<int> * ll2=NULL;

    int m;
    cout<<"enter the length of link list : ";
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int  v;
        cout<<"enter the value : ";
        cin>>v;
        ll2->create(ll2,v);
    }


    if(( ll1->sum(ll1) - ll2->sum(ll2) )> ll1->last_node(ll1) )
    {

        while(ll1!=NULL && ( (ll1->sum(ll1) - ll2->sum(ll2)) >0 ))
        {
            ll1->delete_last_node(ll1);
        }

    }
    else
    {
        while(ll1!=NULL && ((ll1->sum(ll1)-ll2->sum(ll2))>0))
        {
            ll1->delete_first_node(ll1);
        }

    }

    ll1->print(ll1);


}