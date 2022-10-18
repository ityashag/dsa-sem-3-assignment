#include <iostream>
#include<vector>
using namespace std;

template <typename t>
class queue
{
    public: 
    t data;
    queue<t> *next;

    queue(t d)
    {
        this->data=d;
        this->next=NULL;
    }

    void push(queue<t> *  & q,t d)
    {
        queue<t> * n=new queue <t> (d);
        if(q==NULL)
        {
            q=n;
            return;
        }
        else
        {
            queue<t> * temp = q;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            
        }

    }

    void pop(queue<t> * & q)
    {
        if(q!=NULL)
        {
            queue <t> * r=q;
            q=q->next;
            delete (r);
        }


    }

    t top(queue<t> * & q)
    {
        if(q!=NULL)
        {
            return q->data;
        }
        return NULL;

    }

    bool isempty(queue<t> * & q)
    {
        return q==NULL ? true : false;


    }

};

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }

    node *insert_into_bst(node *root, int d)
    {
        if (root == NULL)
            return new node(d);
        if (root->data < d)
        {
            root->right = insert_into_bst(root->right, d);
        }
        else if (root->data > d)
        {
            root->left = insert_into_bst(root->left, d);
        }
        else
        {
            cout << "\nduplicat data : ";
            return root;
        }
    }

    void insert(node * & root)
    {
        int d;
        cout << "enter the data (-1 to stop) : ";
        cin >> d;
        while (d != -1)
        {
            root = insert_into_bst(root, d);
            cout << "enter the data (-1 to stop) : ";
            cin >> d;
        }
    }

    void inorder(node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    int min_val(node *root)
    {
        node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    node *delete_bst(node *root, int d)
    {
        if (root == NULL)
            return NULL;
        if (root->data < d)
        {
            root->right = delete_bst(root->right, d);
        }
        else if (root->data > d)
        {
            root->left = delete_bst(root->left, d);
        }
        else
        {
            if (root->left == NULL)
            {
                node *a = root->right;
                delete root;
                return a;
            }
            else if (root->right == NULL)
            {
                node *a = root->left;
                delete root;
                return a;
            }
            else if (root->left != NULL && root->right != NULL)
            {
                int x = min_val(root);
                root->data = x;
                root->right = delete_bst(root->right, x);
                return root;
            }
        }
    }

    void element_to_delete(node * root,int a,int b,vector <int> &v)
    {
        if(root==NULL) return;
        if(root->data>=a && root->data<=b ) v.push_back(root->data);
        element_to_delete(root->left,a,b,v);
        element_to_delete(root->right,a,b,v);
    }

    void delete_bst_between(node * & root,int a,int b)
    {
        vector<int> v;

        element_to_delete(root,a,b,v);

        for(int i=0;i<v.size();i++)
        {
            root=root->delete_bst(root,v[i]);
        }
    }

    void level_order(node * root)
    {
        if(root==NULL) {cout<<"NULL"; return;}
        queue<node *> *q=NULL;
        q->push(q,root);
        q->push(q,NULL);

        while(!q->isempty(q))
        {
            node * f = q->top(q);
            q->pop(q);

            if(f==NULL)
            {
                if(!q->isempty(q))
                {
                    q->push(q,NULL);
                }
                cout<<endl;
            }
            else
            {
                cout<<f->data<<" ";

                if(f->left)
                {
                    q->push(q,f->left); 

                }
                if(f->right)
                {
                    q->push(q,f->right);

                }

            }
        }
    }
};

int main()
{
    node *root = NULL;

    root->insert(root);

    cout << "\n level order : ";
    root->level_order(root);

    int d;
    cout << "\nenter  (-1 to stop or any number to continue ) : ";
    cin >> d;
    while (d != -1 && root!= NULL)
    {
        int a , b;
        cout<<"\nenter the a and b : ";
        cin>>a>>b;
        root->delete_bst_between(root,a,b);

        cout << "\nlevel order : ";
        root->level_order(root);

        cout << "\nenter  (-1 to stop or any number to continue ) : ";
        cin >> d;
    }
}