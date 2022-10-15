#include<iostream>

using namespace std;

class node
{
    public : 
    int data;
    node * next;
    node * prev;


    node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }

    void create(node * & head,int d)
    {
        node * n=new node(d);
        if(head==NULL)
        {
            head=n;
            return;
        }
        else{
            node * temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            n->prev=temp;
        }
    }

    node * rev(node * head)
    {
        if(head==NULL || head->prev==NULL) return head;
        node * ch=rev(head->prev);
        head->prev->prev=head;
        head->prev=NULL;
        return ch;
    }
    void reverse(node * &head)
    {

        head=head->rev(head);

        node * prev=NULL;
        node * curr=head;
        node * next;

        while(curr!=NULL)
        {
            next=curr->next;
            //next
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        //prev
        head=prev;
        node * tail =head->rev(head);

        node* temp = head;

    }

    void solve(node * & head)
    {
        if(head->next==NULL) return;
        node * slow=head;
        node * fast=head;
        node * prev;

        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL) fast=fast->next;
            prev=slow;
            slow=slow->next;
            

        }



        prev->next=NULL;
        slow->prev=NULL;

        node * s1=head;
        node * s2=slow;
        s2->reverse(s2);
        node* s1n=s1->next;
        node * s2n=s2->next;

        while(s2)
        {
            s1->next=s2;
            s2->prev=s1;
            s2->next=s1n;
            if(s1n!=NULL) s1->prev=s2;
            s1=s1n;
            s2=s2n;
            if(s1n!=NULL)s1n=s1n->next;
            if(s2n!=NULL)s2n=s2n->next;
        }
    }
    void print(node * & head)
    {
        node* temp = head;

        cout<<endl;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};

int main()

{
    node* h=NULL;
    int n;
    cout<<"ENTER THE NUMBER OF ELEMENTS :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the element "<<i+1<<" : ";
        int d;
        cin>>d;
        h->create(h,d);
    }
    cout<<"input : ";
    h->print(h);

    h->solve(h);
    cout<<"\noutput : ";
    h->print(h);

}


