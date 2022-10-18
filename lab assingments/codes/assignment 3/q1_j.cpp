#include<iostream>
#include<set>
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
    void second_largest(node <t>* &head)
    {
        set<t> s;
        node <t>* temp=head;
        while(temp!=NULL)
        {
            s.insert(temp->data);
            temp=temp->next;
        }

        auto it = s.end();
        it--;
        it--;
        cout<<"the second largest element is : "<<*it;

        cout<<"\n";

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
    head->second_largest(head);




}