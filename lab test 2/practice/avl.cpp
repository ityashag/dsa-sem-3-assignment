#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    void height_cal(Node *root, int &c, int h)
    {
        if (root == NULL)
        {
            c = max(h, c);
            return;
        }
        height_cal(root->left, c, h + 1);
        height_cal(root->right, c, h + 1);
    }

    int height(Node *root)
    {
        int c = 0;
        height_cal(root, c, 0);
        return c;
    }

    int get_bf(Node *root)
    {
        if (root == NULL)
            return -1;
        return height(root->left) - height(root->right);
    }

    int min_d(Node *root)
    {
        Node *c = root->right;
        while (c->left != NULL)
        {
            c = c->left;
        }
        return c->data;
    }

    Node *left_r(Node *x)
    {
        Node *y = x->left;
        Node *b = y->right;
        y->right = x;
        x->left = b;
        return y;
    }

    Node *right_r(Node *x)
    {
        Node *y = x->right;
        Node *b = y->left;
        y->left = x;
        x->right = b;
        return y;
    }
    Node *insertToAVL(Node *root, int data)
    {
        // Your code here
        if (root == NULL)
        {
            return new Node(data);
        }
        if (root->data < data)
        {
            root->right = insertToAVL(root->right, data);
        }
        else if (root->data > data)
        {
            root->left = insertToAVL(root->left, data);
        }

        int bf = get_bf(root);
        if (bf > 1 && get_bf(root->left) >= 0)
        {
            return left_r(root);
        }
        if (bf > 1 && get_bf(root->left) < 0)
        {
            root->left = right_r(root->left);
            return left_r(root);
        }
        if (bf < -1 && get_bf(root->right) <= 0)
        {
            return right_r(root);
        }
        if (bf < -1 && get_bf(root->right) > 0)
        {
            root->right = left_r(root->right);
            return right_r(root);
        }
        return root;
    }

    void insert(Node * & root)
    {
        int data;
        cout<<"enter data (-1 to stop) : ";
        cin>>data;
        while(data!=-1)
        {
            root=insertToAVL(root,data);
             cout<<"enter data (-1 to stop) : ";
        cin>>data;

        }
    }

    Node *deleteNode(Node *root, int data)
    {
        // add code here,
        if (root == NULL)
        {
            return root;
        }
        if (root->data < data)
        {
            root->right = deleteNode(root->right, data);
        }
        else if (root->data > data)
        {
            root->left = deleteNode(root->left, data);
        }
        else
        {
            if (root->left == NULL)
            {
                Node *a = root->right;
                delete root;
                return a;
            }
            if (root->right == NULL)
            {
                Node *a = root->left;
                delete root;
                return a;
            }
            if (root->left != NULL && root->right != NULL)
            {
                int x = min_d(root);
                root->data = x;
                root->right = deleteNode(root->right, x);
            }
        }

        if (root == NULL)
        {
            return root;
        }

        int bf = get_bf(root);
        if (bf > 1 && get_bf(root->left) >= 0)
        {
            return left_r(root);
        }
        if (bf > 1 && get_bf(root->left) < 0)
        {
            root->left = right_r(root->left);
            return left_r(root);
        }
        if (bf < -1 && get_bf(root->right) <= 0)
        {
            return right_r(root);
        }
        if (bf < -1 && get_bf(root->right) > 0)
        {
            root->right = left_r(root->right);
            return right_r(root);
        }
        return root;
    }

    void inorder(Node * root)
    {
        if(root==NULL) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }
};


int main()
{
    Node * root=NULL;
    root->insert(root);
    cout<<"\ninorder : ";
    root->inorder(root);




    root->deleteNode(root,10);
    cout<<"\nAfter deletion inorder : ";
    root->inorder(root);
}
