#include<iostream>
#include<unordered_map>
using namespace std;

class node 
{
    public: 
    int data;
    node * left;
    node * right;

    node (int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    } 
    node * insert()
    {
        cout<<"enter the data :(-1 for NULL) ";
        int d;
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

        return root;

    }

    void sibling(node * root,int h,unordered_map<int,pair<int,int>> &m)
    {
        if(root==NULL) return;

        if(root->left)
        {
            m[root->left->data]={h+1,root->data};
        }
        if(root->right)
        {
            m[root->right->data]={h+1,root->data};
        }

        sibling(root->left,h+1,m);
        sibling(root->right,h+1,m);

    }


};

int main()

{
    node *root=NULL;
    root=root->insert();

    unordered_map<int,pair<int,int>> m;

    root->sibling(root,0,m);
    int a,b;
    cout<<"enter the 2 nodes : ";
    cin>>a>>b;

    auto i=m.find(a);
    auto j=m.find(b);
    if(i!=m.end() && j!=m.end())
    {
       
        if(i->second.first && j->second.first && i->second.second  !=j->second.second )
        {
            cout<<"they are cousin .";
        }
        else if(i->second.first == j->second.first)
        {
            cout<<"they have same parents : ";
        }
        else
        {
            cout<<"they are not at same level ";
        }
    }
    else
    {
        cout<<"element aur not present : ";

    }
}

// 1 2 4 7 -1 -1 -1 -1 3 6 8 -1 -1 9 -1 -1 -1