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

    void delete_node(node<t> * &head)
    {
        t v;
        cout<<"enter the value to be deleted  : ";
        cin>>v;

        node<t> * temp=head;
        if(temp->data==v)
        {
            if(temp->next!=NULL){
            head=temp->next;}
            else head=NULL;
            temp->next=NULL;
            delete temp;
            
            return;
        }

        while(  temp->next!=NULL && temp->next->data!=v)
        {
            temp=temp->next;
        }
        if(temp->next==NULL || temp==NULL) {cout<<"not found \n"; return;}

        node<t> * to_del=temp->next;

        temp->next=to_del->next;
        to_del->next=NULL;
        delete to_del;
        
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
                head->delete_node(head);
                cout<<"NEW LINK LIST : ";
                head->print(head);
            }
        }


}