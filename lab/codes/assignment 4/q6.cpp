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
    void create(node * & head)
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
    void searchi(node * & head)
    {
        int d=0 ,mi=INT_MAX,ma=INT_MIN;
        node* temp=head;
        while(temp!=NULL)
        {

            if(temp->data<mi)
            {
                mi=temp->data;
            }

            if(temp->data>ma)
            {
                ma=temp->data;
            }
            d++;
            temp=temp->next;

        }
        cout<<"size : "<<d<<" min : "<<mi<<" max : "<<ma<<endl;

    }
};

int main()
{
    int n;
    cout<<"enter the length of link list : ";
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        head->create(head);

    }
    head->print(head);
    head->searchi(head);
}

