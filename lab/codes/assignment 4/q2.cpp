
#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
    void in_at_end(node * & head)
    {

        int d;
        cout<<"enter the data  : ";
        cin>>d;
        node * n=new node(d);
        if(head==NULL)
        {
            head=n;
            return;
        }
        node * temp=head;
        while(temp->next!=NULL)temp=temp->next;
        temp->next=n;
        return;
    }
    void in_at_beg(node * & head)
    {

        int d;
        cout<<"enter the data  : ";
        cin>>d;
        node * n=new node(d);
        if(head==NULL)
        {
            head=n;
            return;
        }
        n->next=head;
        head=n;
        return;
    }
    void in_at_pos(node * & head)
    {

        int d;
        cout<<"enter the data  : ";
        cin>>d;
        int pos;
        cout<<"enter the pos : ";
        cin>>pos;
        node * n=new node(d);
        if(head==NULL)
        {
            head=n;
            return;
        }
        else if(pos==1)
        {
            n->next=head;
            head=n;
            return;
        }
        else
        {
            int cn=1;
            node * temp=head;
            int s=0;
            while(temp->next!=NULL)
            {
                s++;
                temp=temp->next;
            }
            if(pos>++s)
            {
                temp->next=n;
                return;
            }
            temp=head;
            while(cn<pos-1)
            {
                cn++;
                temp=temp->next;
            }
            n->next=temp->next;
            temp->next=n;
        }

    }
    void print(node*&head)
    {

        node* temp=head;
        if(head==NULL)
        {

            cout<<"NULL\n";
            return;
        }
        while(temp!=NULL)
        {

            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

};

int main()
{
    int n;
    cout<<"enter the value of n when 3n is the length of link list  : ";
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        head->in_at_beg(head);
    }
        head->print(head);
        for(int i=0;i<n;i++)
    {
        head->in_at_pos(head);
    }
        head->print(head);
        for(int i=0;i<n;i++)
    {
            head->in_at_end(head);
    }
    head->print(head);


}
