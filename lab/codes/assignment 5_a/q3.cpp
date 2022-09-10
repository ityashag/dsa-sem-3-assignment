#include<iostream>
using namespace std;
class node{
    public:
    char data;
    node* next;
    node(char d)
    {

        this->data=d;
        this->next=NULL;
    }

    void create(node* &head)
    {
        char c;
        cout<<"enter the data : ";
        cin>>c;
        node* n=new node(c);
        if(head==NULL)
        {

            head=n;
            return;

        }
        node* temp=head;
        while(temp->next!=NULL)temp=temp->next;
        temp->next=n;
    }
    node * rev( node * & head)
    {

        if(head==NULL || head->next==NULL)return head;
        node* c=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return c;

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
    node* head1=NULL;
    cout<<"enter the length of link list  : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {

        head1->create(head1);
    }
    cout<<"before reverse : ";
    head1->print(head1);
    cout<<"link list after reverse : ";
    
    head1=head1->rev(head1);
    head1->print(head1);

}
