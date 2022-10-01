#include<iostream>
using namespace std;

class node
{
    public:
    int id;
    string name;
    string dep;
    node * next;

    node(int i,string n,string d)
    {
        this->id=i;
        this->name=n;
        this->dep=d;
        this->next=NULL;
    }
    void create(node *& head,int i,string u,string d)
    {
        node* n = new node(i,u,d);

        if(head==NULL)
        {
            n->next=n;
            head=n;
            return ;

        }
        node* temp=head;
        while(temp->next!=head) temp=temp->next;

        n->next=temp->next;
        temp->next=n;
    }

    void search_d(node *& head,string d)
    {
        node* temp=head;
        while(temp->next!=head)
        {
            if(temp->dep==d)
            {
                cout<<"employee id : "<<temp->id<<" employee name : "<<temp->name<<endl;
            }
            temp=temp->next;
        }

    }
    
};

int main()
{

    int n=5;

    node* head=NULL;

    for(int i=0;i<n;i++)
    {
        int j;
        string n,d;
        cout<<"enter the employee id_ : ";
        cin>>j;
        cout<<"enter the name : ";
        cin>>n;
        cout<<"enter the dept : ";
        cin>>d;
        head->create(head,j,n,d);
    }

    string s;
    cout<<"enter the depeartment:  ";
    cin>>s;
    head->search_d(head,s);
}
