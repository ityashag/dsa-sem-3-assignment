#include<iostream>
#include<stack>
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
    void reverse(node <t>* &head)
    {
        stack<t> s;
        node <t>* temp=head;
        while(temp!=NULL)
        {
            s.push(temp->data);
            temp=temp->next;
        }

        while(!s.empty())
        {
            cout<<s.top()<<" -> ";
            s.pop();
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

    cout<<"original link list : ";
    head->print(head);
    cout<<"\n";
    cout<<"reverse link list : ";
    head->reverse(head);




}