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
    cout<<"enter the length of s1  : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {

        head1->create(head1);
    }

    head1->print(head1);
    node* fast=head1;
    node* slow=head1;
    while(fast->next!=NULL)
    {
        fast=fast->next;

        if(fast->next!=NULL)fast=fast->next;
        slow=slow->next;
    }
    if(head1->next==NULL)
    {
        cout<<"yes palindrom";
        return;
    }
    if(head1->next->next==NULL)
    {
        if(head1->data==head1->next->data)
        {
            cout<<"yes palindrom";
        }
        else cout<<"not palindrom";
        return 1;
    }
    slow->next=slow->rev(slow->next);
    node * temp=head1;
    slow=slow->next;
    while(slow!=NULL)
    {

        if(slow->data!=temp->data){cout<<"no : palindrom"; return 1;}
        slow=slow->next;
        temp=temp->next;
    }
    cout<<"yes : palindrom";



}
