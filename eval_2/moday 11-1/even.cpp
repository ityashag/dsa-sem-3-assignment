#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    node *insert_into_bst(node *root, int data)
    {
        if (root == NULL)
            return new node(data);
        if (root->data < data)
            root->right = insert_into_bst(root->right, data);
        else if (root->data > data)
            root->left = insert_into_bst(root->left, data);
        else
        {
            cout << "\nduplicate data\n";
            return root;
        }
    }
    void insert(node *&root)
    {
        int data;
        cout << "enter data (-1 to stop) :";
        cin >> data;

        while (data != -1)
        {
            root = insert_into_bst(root, data);
            cout << "enter data (-1 to stop) :";
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

    void solve(node *root, int key, int &ans, int &mini)
    {
        if (root == NULL)
            return;

        if (root->data <= key)
        {
            if (mini > abs(root->data - key))
            {
                ans = root->data;
                mini = abs(root->data - key);
            }
            solve(root->right, key, ans, mini);
        }
        else
        {
            if (mini > abs(root->data - key))
            {
                ans = root->data;
                mini = abs(root->data - key);
            }
            solve(root->left, key, ans, mini);
        }
    }

    int closertinTree(node *root, int key)
    {
        int ans = -1;
        int mini = INT32_MAX;

        solve(root, key, ans, mini);

        return ans;
    }
};

int main()
{
    node *root = NULL;

    root->insert(root);

    cout << "\ninorder: ";

    root->inorder(root);

    int data;
    cout << "\nenter key(-1 to stop) :";
    cin >> data;

    while (data != -1)
    {
        cout << "\nthe closest element is : " << root->closertinTree(root, data);
        cout << "\nenter data (-1 to stop) :";
        cin >> data;
    }
}