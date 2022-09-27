#include<iostream>
#include<queue>

using namespace std;

template<typename t>
class tree
{
    public:
    t data;
    tree * left;
    tree * right;

    tree (t d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

    tree<t> *  create(tree<t> * root)
    {
        t d;
        cout<<"enter the data (-1 for NULL): ";
        cin>>d;


        if(d==-1)
        {
            return NULL;
        }
        root=new tree(d);

        cout<<"for the left of "<<d<<" ";
        root->left=create(root->left);

        cout<<"for the right of "<<d<<" ";
        root->right=create(root->right);

        return root;
    }

    void deletion(tree<t> * & root, tree <t>* p)
    {

        queue<tree*> q;
        q.push(root);

        while(!q.empty())
        {
            tree<t> * temp=q.front();
            q.pop();
            if(temp==p)
            {
                root=NULL;
                return;
            }

            if(temp->right)
            {
                if(temp->right==p)
                {

                    temp->right=NULL;
                    return;
                }
                else
                {
                    q.push(temp->left);
                }
            } 
            
            if(temp->left)
            {
                if(temp->left==p)
                {

                    temp->left=NULL;
                    return;
                }
                else
                {
                    q.push(temp->left);
                }
            } 

        }

    }

    void del(tree<t> * & root, int key)
    {

        queue<tree*> q;
        q.push(root);
        tree<t> * key_node=NULL;
        tree <t>* temp=NULL;

        while(!q.empty())
        {
            temp=q.front();
            q.pop();

            if(temp->data==key)
            {
                key_node=temp;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

        }

        if(key_node!=NULL)
        {
            int x=temp->data;
            deletion(root,temp);

            key_node->data=x;
        }

    }

     void inorder( tree<t>* &root)
    {
        if(root==NULL)return ;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }
    



    
};


int main()
{

    tree<int> * root;
    root=root->create(root);

    root->inorder(root);
    int n;
    cout<<"\nenter the data to delete : ";
    cin>>n;

    root->del(root,n);

    cout<<endl<<"after deletion inorder : ";

    root->inorder(root);


}