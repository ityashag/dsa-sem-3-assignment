#include<iostream>

using namespace std;

//treaded tree

class ttree
{
    public:
    int data;
    ttree * left, * right;
    bool lthread;
    bool rthread;

    ttree(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
        lthread=true;
        rthread=true;

    }

    ttree * insert(ttree *root,int key)
    {
        ttree * ptr=root;
        ttree * par=NULL;

        while(ptr!=NULL)
        {
            if(key==ptr->data)
            {
                cout<<"duplicate key : ";
                return root;
            }
            par=ptr;

            if(key<ptr->data)
            {
                if(ptr->lthread==false)
                {
                    ptr=ptr->left;
                }
                else break;
            }
            else
            {
                if(ptr->rthread==false)
                {
                    ptr=ptr->right;
                }
                else break;
            }
        }


        ttree * n=new ttree(key);

        if(par==NULL)
        {
            root=n;
        }
        else if(par->data>key)
        {

            n->left=par->left;
            n->right=par;
            par->lthread=false;
            par->left=n;
        }
        else
        {
            n->right=par->right;
            n->left=par;
            par->rthread=false;
            par->right=n;
        }

        return root;
    }


    ttree * inorder_successor(ttree * root)
    {
        if(root->rthread==true)
        {
            return root->right;
        }
        root=root->right;
        while(root->lthread==false)
        {
            root=root->left;
        }
        return root;

    }
    void inorder(ttree * root)
    {
        if(root==NULL){ cout<<"tree empty\n"; return;}

        ttree * ptr=root;
        while(ptr->lthread==false)
        {
            ptr=ptr->left;
        }
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=inorder_successor(ptr);
        }


    }


};

int main()
{
    ttree * root=NULL;
    int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    cout<<"ENTER THE NODES : ";
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        root =root -> insert(root, d);

    }
    cout<<"inorder traversal : ";

    root->inorder(root);

}