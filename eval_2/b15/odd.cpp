#include <iostream>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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
            return root;
        }
    }

    void insert(node *&r)
    {
        int data;
        cout << "enter the data : ( -1 for stop entering data) ";
        cin >> data;
        while (data != -1)
        {
            r = insert_into_bst(r, data);
            cout << "enter the data : ( -1 for stop entering data) ";
            cin >> data;
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
    void sr(node *root, int key, node *&f)
    {
        if (root == NULL)
            return;
        if (root->data == key)
        {
            f = root;
            return;
        }
        sr(root->left, key, f);
        sr(root->right, key, f);
    }

    void solve(node * & root,int h)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            cout<<"\nleaf node("<<root->data<<") is at distance "<<h<<" from the given node .\n";
        }

        solve(root->left,h+1);
        solve(root->right,h+1);
    }

};
int main()
{
    node *root = NULL;

    root->insert(root);
    cout << "\n inorder traversal :";
    root->inorder(root);
    cout << "\n";
    int c;
    cout << "enter the value of node :(-1 to exit) ";
    cin >> c;
    while (c != -1)
    {
        node *f = NULL;
        root->sr(root, c, f);
        if (f == NULL)
        {
            cout << "\nthe value is not present : ";
        }
        else
        {
           root-> solve(f,0);

        }
        cout << "\nenter the value of node :(-1 to exit) ";
        cin >> c;
    }
}