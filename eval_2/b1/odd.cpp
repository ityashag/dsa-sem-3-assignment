#include<iostream>
using namespace std;
#include<map>

class node
{
    public: 
    int data;
    node * right;
    node *left;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

    node * insert()
    {
        int d;
        cout<<"enter the data : ";
        cin>>d;
        if(d==-1)
        {
            return NULL;
        }

        node * root=new node (d);

        cout<<"for the left of "<<d<<" ";
        root->left=insert();
        cout<<"for the right of "<<d<<" ";
        root->right=insert();
    }
    void vertical(node *root,int h,map<int,int> & m)
    {
        if(root==NULL) return;

        m[h]+=root->data;

        vertical(root->left,h-1,m);
        vertical(root->right,h+1,m);
    }




};

int main()
{
    node * root=NULL;
    root=root->insert();

    map<int,int> m;

    root->vertical(root,0,m);

    cout<<"\nvertical sum : ";
    for(auto i: m)
    {
        cout<<i.second<<" ";
    }



}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
