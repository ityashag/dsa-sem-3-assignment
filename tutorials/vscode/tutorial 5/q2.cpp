#include<iostream>
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

    void insertion_at_end(node * & head,int d)
    {
        node * n = new node (d);
        if(head==NULL)
        {
            n->next=n;
            head=n;
            return;
        }
        node* temp=head->next;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }

    
    void insertion_at_beg(node * & head,int d)
    {
        node * n = new node (d);
        if(head==NULL)
        {
            n->next=n;
            head=n;
            return;
        }
        node* temp=head->next;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
        head=n;
    }

    void in_at_pos(node * & head, int d,int pos)
    {
        if(pos==1)
        {
            head->insertion_at_beg(head,d);
            return;
        }
        node * n= new node(d);
        node* temp=head;
        int ct=1;
        while(ct<pos-1)
        {
            ct++;
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
        

    }

    void print(node * & head)
    {
        node* temp=head->next;
        cout<<"->"<<head->data<<"->";
        while(temp!=head)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"\n";
    }

};
int main()
{
    node* head=NULL;

    int t=1;
    while(t)
    {
        cout<<"enter 1 to insert at beg \nenter 2 to insert at any pos \nenter 3 to insert at end\nenter 4 to print \nenter 0 to exit\n";
        cin>>t;
        int n,pos;
        switch(t)
        {
            case 1:
                cout<<"enter data : ";
                cin>>n;
                head->insertion_at_beg(head, n);
                break;
            case 2:
                cout<<"enter data : ";
                cin>>n;
                cout<<"enter pos : ";
                cin>>pos;
                head->in_at_pos(head,n,pos);
                break;
            case 3:
                cout<<"enter data : ";
                cin>>n;
                head->insertion_at_end(head, n);
                break;
            case 4:
                head->print(head);
                break;
        }
    }
}