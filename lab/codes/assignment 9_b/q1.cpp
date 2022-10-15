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
        int d;
        cout << "enter the data (-1 to end) : ";
        cin >> d;
        while (d != -1)
        {
            root = insert_into_bst(root, d);
            cout << "enter the data (-1 to end) : ";
            cin >> d;
        }
    }

    void inorder(node * root,vector<int> & a)
    {
        if(root==NULL) return;

        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }

};

int main()
{
    // queue<int> * q=NULL;
    // for(int i=0;i<10;i++)
    // {
    //     q->push(q,i+1);
    // }
    // while(!q->isempty(q))
    // {
    //     cout<<q->top(q)<<" ";
    //     q->pop(q);
    // }

    node * root=NULL;
    root->insert(root);
    vector<int> a;
    root->inorder(root,a);

    int k;
    cout<<"enter the value of k : ";
    cin>>k;

    if(k>a.size())
    {
        cout<<"k elemnts are not present : ";
    }
    else{
        cout<<"kth largest element is "<<a[a.size()-k];
    }
}