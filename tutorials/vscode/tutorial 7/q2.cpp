

#include<iostream>
using namespace std;


template<typename t>
class tree
{
    public:
    t data;
    tree * right;
    tree * left;

    tree(t d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

    tree * create (tree *& root)
    {
        t d ;
        cout<<"enter the data : ";
        cin>>d;

        root=new tree (d);
        
        if(d==-1)
        {
            return NULL;
        }

        cout<<"for the left of "<<d<<" : ";
        root->left=create(root->left);
         cout<<"for the right of "<<d<<" : ";
        root->right=create(root->right);
        return root;

    }

    void height(tree * root, int h, int & ans)
    {
        if(root==NULL) {ans=max(ans,h); return ;}

        height(root->left,h+1,ans);
        height(root->right,h+1,ans);
    }

    void inorder( tree * root)
    {
        if(root==NULL)return ;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }


};


int main()
{

    tree <int> * root;
    root=root->create(root);

    cout<<"\n inorder : ";
    root->inorder(root);
    int ans=-25;
    root->height(root,0,ans);
    cout<<"height : "<<ans;


}