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

    void update_node(node<t> * &head)
    {
        t v;
        cout<<"enter the value to be updated : ";
        cin>>v;
        int new_data;
        cout<<"enter the update value : ";
        cin>>new_data;

        node<t> * temp=head;
        if(temp->data==v)
        {
            temp->data=new_data;
            return;
        }

        while(  temp->next!=NULL && temp->next->data!=v)
        {
            temp=temp->next;
        }
        if(temp->next==NULL || temp==NULL) {cout<<"not found \n"; return;}

        temp->next->data=new_data;
        
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
                head->update_node(head);
                cout<<"NEW LINK LIST : ";
                head->print(head);
            }
        }


}