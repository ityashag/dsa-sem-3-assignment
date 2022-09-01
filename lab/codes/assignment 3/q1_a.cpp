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


    int search(node<t> * &head)
    {
        t v;
        cout<<"enter the key : ";
        cin>>v;
        int count =0;

        node<t> * temp=head;
        while(temp!=NULL)
        {
            if(temp->data==v)return count;

            count++;
            temp=temp->next;
        }

        return -1;

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
            cout<<"enter 1 to continue or 0 to exit search";
            cin>>t;

            if(t)
            {
                int pos=head->search(head);
                if(pos==-1) cout<<"element is not found \n";
                else cout<<"the position is : "<<pos+1<<" \n";
            }
        }


}