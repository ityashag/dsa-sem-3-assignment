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

    void create(node <t>* &head)
    {
        t v;
        cout<<"enter the value : ";
        cin>>v;
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

    void insert_at_head(node<t> * &head)
    {
        t v;
        cout<<"enter the value : ";
        cin>>v;
        node<t> * n=new node<t>(v);
        if(head==NULL)
        {
            head=n;
            return;
        }

        n->next=head;
        head=n;

    }

    void insert_at_any_pos(node<t>* &head)
    {
        int pos;
        cout<<"enter the position : ";
        cin>>pos;
        if(pos==1)
        {
            insert_at_head(head);
            return;
        }
        else{
             t v;
            cout<<"enter the value : ";
            cin>>v;
            node<t> * n=new node<t>(v);
            int count=1;
            node<t> * temp=head;
            while(count<pos-1)
            {
                temp=temp->next;
                count++;
            }
            n->next=temp->next;
            temp->next=n;
            
        }
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

};

int main()
{
    node <int> * head=NULL;
    int n;
    cout<<"enter the length of link list : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        head->create(head);
    }

   // head->print(head);
    cout<<"\n";

    int t=1;
        while(t)
        {
            cout<<"enter 1 to continue or 0 to exit delete ";
            cin>>t;

            if(t)
            {
                head->insert_at_any_pos(head);
                cout<<"NEW LINK LIST : ";
                head->print(head);
            }
        }


}