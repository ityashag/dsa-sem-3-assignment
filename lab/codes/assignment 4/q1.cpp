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
        int d;
        cout<<"enter the element for search  : ";
        cin>>d;
        node* temp=head;
        if(head==NULL)
        {

            cout<<"the list is empty : not present\n";
            return;
        }
        while(temp!=NULL)
        {

            if(temp->data==d)
            {
                cout<<"present \n";
                return;
            }
            temp=temp->next;
        }
        cout<<"not present\n";

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
