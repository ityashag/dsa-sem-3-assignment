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

    void bubble_Sort(node<t> *&head)
    {
        // bubble sort
        node<int> *i = head;
        while (i != NULL)
        {
            node<int> *j = head;
            while (j->next != NULL)
            {
                if (j->data > j->next->data)
                {
                    node<int> *temp = new node<int>(j->data);
                    j->data = j->next->data;
                    j->next->data = temp->data;
                }
                j = j->next;
            }
            i = i->next;
            // head->print(head);
        }
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
    node<int> * temp=ll1;

    while(temp!=NULL)
    {
        ll2->create(ll2,temp->data);
        temp=temp->next;
    }

    ll2->bubble_Sort(ll2);

   

    temp=ll1;

    node<int> * temp1=ll2;


    node<int> * ll3=NULL;

   ll1->bubble_Sort(ll1);

    for(int i=0;i<2*n;i++)
    {
        if(temp==NULL)
        {
            while(temp1!=NULL)
            {
                ll3->create(ll3,temp1->data);
                temp1=temp1->next;
                i++;
            }
        }
        else if(temp1==NULL)
        {
            while(temp!=NULL)
            {
                ll3->create(ll3,temp->data);
                temp=temp->next;
                i++;
            }
        }
        else if(temp==NULL && temp1==NULL) break;
        else if(temp->data<temp1->data)
        {
            ll3->create(ll3,temp->data);
            temp=temp->next;
        }
        else 
        {
            ll3->create(ll3,temp1->data);
            temp1=temp1->next;
            
        }

    }

    ll3->print(ll3);

}