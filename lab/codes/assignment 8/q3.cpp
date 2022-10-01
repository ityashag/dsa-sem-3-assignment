#include<iostream>
using namespace std;
class tree
{

    public: 
    int data;
    tree* left;
    tree* right;

    tree(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

tree * insert_into_bst(tree * root,int d)
{
    if(root==NULL)
    {
        root=new tree(d);
        return root;
    }
    if(d>root->data)
    {
        root->right=insert_into_bst(root->right,d);
    }
    else
    {
        root->left=insert_into_bst(root->left,d);
    }



}

void take_input(tree * & root)
{
    int data;
    cout<<"enter data (-1 to stop): ";
    cin>>data;
    while(data!=-1)
    {
        root=insert_into_bst(root,data);
        cout<<"enter data (-1 to stop): ";
        cin>>data;
        
    }
    
}



