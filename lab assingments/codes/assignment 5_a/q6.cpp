#include<bits/stdc++.h>
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
    void sort( node * & head)
    {

       node* i=head;
       while(i!=NULL)
       {
           char d=i->data;
           node * j=i;
           node* min=i;
           while(j!=NULL)
           {
               if(j->data<min->data)
               {
                   min=j;

               }
               j=j->next;
           }

           i->data=min->data;
           min->data=d;
           i=i->next;
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
    node* head1=NULL;
    cout<<"enter the length of s1  : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {

        head1->create(head1);
    }
    head1->sort(head1);
    head1->print(head1);
    map<char,int> m;
    node* temp=head1;

    while(temp!=NULL)
    {
        m[temp->data]++;
        temp=temp->next;
    }
    cout<<"node : occurrence\n";
    for(auto i:m)
    {
        cout<<i.first<<"   :"<<i.second<<endl;
    }


}
