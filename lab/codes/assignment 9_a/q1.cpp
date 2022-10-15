#include <iostream>

#include <vector>

int cc = 0;

using namespace std;
template <typename t>
class queue
{
public:
    t data;
    queue<t> *next;

    queue(t d)
    {
        this->data = d;
        this->next = NULL;
    }

    void push(queue<t> *&q, t d)
    {
        queue<t> *n = new queue<t>(d);

        if (q == NULL)
        {
            q = n;
            return;
        }

        queue<t> *temp = q;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void pop(queue<t> *&q)
    {
        if (q != NULL)
        {
            queue<t> *to = q;
            q = q->next;
            delete to;
        }
    }

    t top(queue<t> *&q)
    {
        if (q != NULL)
            return q->data;
        return 0;
    }

    bool isempty(queue<t> *&q)
    {
        return q == NULL ? true : false;
    }
};

class node
{
    node *insert_into_bst(node *root, int d)
    {
        if (root == NULL)
            return new node(d);
        if (d < root->data)
            root->left = insert_into_bst(root->left, d);
        else if (d > root->data)
            root->right = insert_into_bst(root->right, d);
        else
        {
            cout << "\nduplicate data\n";
            return NULL;
        }
        return root;
    }

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

    void insert(node *&root)
    {
        // int d;
        // cout << "enter the data (-1 to end) : ";
        // cin >> d;
        int c = 2000;

        while (c--)
        {
            int r=rand()/10;
            cout<<r<<" ";


            root = insert_into_bst(root, r);
            // cout << "enter the data (-1 to end) : ";
            // cin >> d;
        }
    }

    void inorder(node *root, vector<int> &a)
    {
        if (root == NULL)
            return;

        inorder(root->left, a);
        a.push_back(root->data);
        inorder(root->right, a);
    }

    void search(node *root, int key)
    {
        if (root == NULL)
            return;

        if (root->data == key)
            return;
        search(root->left, key);
        search(root->right, key);
    }

    void height_cal(node *root, int h, int &ans)
    {
        if (root == NULL)
        {
            ans = max(ans, h);
            return;
        }
        height_cal(root->left, h + 1, ans);
        height_cal(root->right, h + 1, ans);
    }

    int height(node *root)
    {
        int ans = 0;
        height_cal(root, 0, ans);
        return ans;
    }
};

int main()
{
    srand(1002);

    int k = 100;

    while(k--)
    {
        node * root = NULL;
        root->insert(root);
        cout << root->height(root)<<"**\n ";
        cc += root->height(root);
    }

    cout << cc;

}

// insertion  
// c=1000 avg 3846    
// c=2000 avg 7727
// c=3000 avg 11577
// c=4000 avg 15500

// searching
// c=1000   15
// c=2000   16
// c=3000   18
// c=4000   19

// height

// c=1000 9.69
// c=2000 16.68
// c=3000 17.04
// c=4000 16.70
