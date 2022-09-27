#include<iostream>
using namespace std;


class tree 
{
    public:
    int data;
    tree * left;
    tree * right;

    tree (int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

    void inorder(tree *& root)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left)inorder(root->left);
        cout<<root->data<<" ";
        if(root->right) inorder(root->right);
    }
};

int search(int in[],int s,int e, int key)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==key) return i;
    }
    return -1;

}
int * c(int in[],int s,int e,int n,int pre[])
{
    int * ans=new int [e-s+1];
    int k=0;

    for(int i=0;i<n;i++)
    {
        if(search(in,s,e,pre[i])!=-1)
        {
            ans[k++]=pre[i];
        }
    }

    return ans;
}

tree * construct ( int in[] , int pre [],int s,int e,int n )
{

    if(s>e)
    {
        return NULL;
    }

    tree * root =new tree(pre[0]);
    if(s==e)
    {
        return root;
    }

    int index=search(in,s,e,pre[0]);

    int * lp=c(in,s,index-1,n,pre);
    int * rp=c(in,index+1,e,n,pre);

    root->left=construct(in,lp,s,index-1,index-s);
    root->right=construct(in,rp,index+1,e,e-index);
    return root;

}


int main()
{
    int n;

    cout<<"enter the value of n : ";
    cin>>n;
    int in[n];
    int pre[n];
   

    cout<<"inorder : ";
    for(int i=0;i<n;i++)
    {
        cin>>in[i];

    }
    cout<<"preorder : ";
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }


    tree * root=construct(in,pre,0,n-1,n);

    root->inorder(root);



}