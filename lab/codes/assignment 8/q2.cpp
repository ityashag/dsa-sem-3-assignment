#include <iostream>
#include <queue>
using namespace std;

class tree
{

public:
    int data;
    tree *left;
    tree *right;

    tree(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    tree *create(tree *&root)
    {
        cout << "enter data (-1 for NULL) : ";
        int d;
        cin >> d;

        root = new tree(d);

        if (d == -1)
        {
            return NULL;
        }
        cout << "for the left of " << d << " ";
        root->left = create(root->left);
        cout << "for the right of " << d << " ";
        root->right = create(root->right);
        return root;
    }

    void print(tree * & root)
    {
          queue<tree *> q;
        q.push(root);
        tree *front;

        while (!q.empty())
        {
            front = q.front();
            q.pop(); 

            cout<<front->data<<" ";
            if (front->left!=NULL)
            {
                q.push(front->left);
            }
            if (front->right!=NULL)
            {
                q.push(front->right);
            }
        }

    }

    void display(tree *&root, int d)
    {
        queue<tree *> q;
        q.push(root);
        tree *front;

        while (!q.empty())
        {
            front = q.front();
            q.pop();

            if (front->data == d)
            {
                break;
            }
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }

        if (front->data==d)
        {
            cout<<" level order is : ";
            while (!q.empty())
            {
                q.pop();
            }

            q.push(front);
            while (!q.empty())
            {
                tree * f = q.front();
                q.pop();

                cout<<f->data<<"  ";
                if (f->left)
                {
                    q.push(f->left);
                }
                if (f->right)
                {
                    q.push(f->right);
                }
            }
        }
        else{
            cout<<"given value is not present ";
        }
    }

    void delete_subtree(tree *& root,int d)
    {
        queue<tree *> q;
        q.push(root);
        tree *front;

        while (!q.empty())
        {
            front = q.front();
            q.pop();

            if( front->right!=NULL && (front->right->data == d))
            {
                front->right=NULL;
                break;
            }
            if( front->left!=NULL && (front->left->data == d))
            {
                front->left=NULL;
                break;
            }
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }

    }


    void deletion(tree * & root, tree * &p)
    {

        queue<tree*> q;
        q.push(root);

        while(!q.empty())
        {
            tree * temp=q.front();
            q.pop();
                  if (temp ==p) {
         temp = NULL;
         delete (p);
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
                    return ;
                }
                else
                {
                    q.push(temp->left);
                }
            } 

        }

    }


    tree * del(tree * & root,int d)
    {
        queue<tree *> q;
        q.push(root);
        tree *front;

        tree * key_node = NULL;

        while (!q.empty())
        {
            front = q.front();
            q.pop();

            if(front->data==d)
            {
                key_node=front;

            } 
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }

        if(key_node!=NULL)
        {
            int x=front->data;
            deletion(root,front);
            key_node->data=x;
        }
 cout<<"**";
        root->print(root);
        cout<<"**";
        return root;
         
    }

    void at_height(tree * &  root,int h, int & height,tree * &  proot)
    {

        if(proot==NULL)
        {
            return;
        }
        if(h==height)
        {
            root=root->del(root,proot->data);
        }

        at_height(root,h+1,height,proot->left);
        at_height(root,h+1,height,proot->right);

    }


};

int main()
{
    tree * root=NULL;
    root=root->create(root);
    cout<<endl;
    root->print(root);
    
    // //displaying a subtree
    // root->display(root,4);

    // //deleting a sub tree
    // root->delete_subtree(root,4);
    // cout<<endl;
    // root->print(root);


    //deletion at a pirticular height
    int height=1;
    root->at_height(root,0,height,root);

    cout<<endl;
    root->print(root);
    

}
