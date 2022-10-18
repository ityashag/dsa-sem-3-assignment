
#include <iostream>
#include<set>

using namespace std;

class node{
    public:
    char data;
    node * next;
    node(char d)
    {
        this->data=d;
        this->next=NULL;
    }
    void create(node * & head,string s, int i)
    {
        char c = s[i];
        node * n=new node(c);
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
    void del(node*&head)
    {
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        s.insert('A');
        s.insert('E');
        s.insert('I');
        s.insert('O');
        s.insert('U');

        if(head== NULL)return;
        if(s.find(head->data)!=s.end()){ if(head->next!=NULL){node * t=head;head=head->next ;delete(t);} else {head=NULL;return;}}
        node* temp=head;
        while(temp->next!=NULL)
        {
            if(s.find(temp->next->data)!=s.end())
            {
                node * to=temp->next;
               temp->next=to->next;
                delete(to);

            }
            else
            {
                temp=temp->next;
            }
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
    string n;
    cout<<"enter the name : ";
    cin>>n;
    node* head=NULL;
   for(int i=0;i<n.length();i++)
   {
       head->create(head,n,i);
   }
      head->print(head);
   head->del(head);
    head->print(head);

}
