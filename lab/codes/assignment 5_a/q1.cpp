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
    
    void del(node*& head1,node*& head2)
    {

        node* t2=head2;
        node* t1=head1;
        int count=0;
        node* s1=NULL;
        node* s2=NULL;
        int c=0;

        while(t1!=NULL)
        {
            node* rr=t1;
            t2=head2;
            while(t2!=NULL)
            {
                node* e=t2;
                if(t2->data==t1->data )
                {
                    s1=t1;
                    c=1;
                    node* c1=t1;
                    node* c2=t2;

                    for(int jj=0;jj<3;jj++)
                    {
                        if(c1->next!=NULL && c2->next!=NULL){c1=c1->next;c2=c2->next; if(c1->data==c2->data) c++;} 
                        
                    }
                    if(c==3)
                    {
                        if(s1==head1)
                        {
                            head1=c1->next;
                            delete(s1);
                        }
                        else 
                        {
                            node* h=head1;
                            while(h->next!=s1)h=h->next;
                            h->next=c1->next;
                            delete(s1);
                        }
                        return;
                    }
                }
                t2=e->next;

            }
            t1=rr->next;

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
    node* head2=NULL;
    cout<<"enter the length of s1  : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {

        head1->create(head1);
    }
    cout<<"enter the length of s2  : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {

        head2->create(head2);
    }
    head1->print(head1);
    head2->print(head2);
    head1->del(head1,head2);
    head1->print(head1);



}
