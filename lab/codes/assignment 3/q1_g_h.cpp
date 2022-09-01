#include<iostream>
#include<map>
#include<vector>
using namespace std;

template<typename t>
class node
{
    public:
    t data;
    node * next;
    node(t d)
    {
        this -> data=d;
        this -> next=NULL;
    }


    void create(node <t> * &head)
    {
        int v;
        cout<<"enter the value : ";
        cin>>v;
        node<t> * n=new node(v);

        if(head==NULL)
        {
            head=n;
            return;
        }

        node<t> * temp=head;

        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=n;
    }

    void delete_node (node <t>* & head,int pos)
    {
        if(pos==1)
        {

            node <t>* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        else
        {
            node <t>* temp=head;
            int curr=1;
            while(curr<pos-1)
            {
                curr++;
                temp=temp->next;
            }
            node<t>* to_del=temp->next;
            temp->next=to_del->next;
            to_del=NULL;
            delete to_del;
        }
    }

    vector<int> sel (node<t>*&head,t d)
    {
        node<t>* temp=head;
        vector<int> ans;
        int count=1;

        while(temp!=NULL)
        {
            if(temp->data==d) ans.push_back( count);
            count++;
            temp=temp->next;
        }

        return ans;
    }


    void print(node<t> * & head)
    {
        node<t>* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL \n";

    }




};

int main()
{
    int t;
    cout<<"enter the length of link list : ";
    cin>>t;
    node<int> * head=NULL;

    for(int i=0;i<t;i++)
    {
        head->create(head);
    }

    head->print(head);

    map<int ,vector<int> >m;
    node <int> * temp=head;

    while(temp)
    {
        if(m[temp->data].size()==0)
        {
            m[temp->data]=head->sel(head,temp->data);
        }
    }

    for(auto i:m)
    {
        if(i.second.size()>2)
        {
            for(int j=1;j<i.second.size()-1;j++)
            {
                cout<<i.second[j]<<"*";
                head->delete_node(head,i.second[j]);
            }
        }
    }

    head->print(head);

    
}