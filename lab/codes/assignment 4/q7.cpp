
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
    node* reverse ( node * & head )
    {
        if(head==NULL ||head->next==NULL)
        {
            return head;
        }
        node * ch= reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return ch;
    }
    void print(node*&head)
    {

        node* temp=head;
        if(head==NULL)
        {

            cout<<"c\n";
            return;
        }
        int n=0;
        while(temp!=NULL)
        {

           n++;
            temp=temp->next;
        }
        temp=head;
        cout<<temp->data<<"( x ^ "<<--n<<" ) ";
        temp=temp->next;
        while(temp!=NULL)
        {
            

            cout<<"+ "<<temp->data<<"( x ^ "<<--n<<" ) ";
            temp=temp->next;
        }
        cout<<" \n";
    }

};

int main()
{
    int n=1;

    node* head=NULL;
while(n){
        head->create(head);
        cout<<"enter 1 to continue link list : ";
        cin>>n;
}

    head->print(head);
    head=head->reverse(head);
    head->print(head);
}
