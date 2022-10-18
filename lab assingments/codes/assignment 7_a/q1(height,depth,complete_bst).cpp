#include <iostream>
using namespace std;

template <typename t>
class queue
{
public:
    t data;
    queue<t> *next;
    queue(t d)
    {
        this->next = NULL;
        this->data = d;
    }

    void push(queue<t> *&q, t d)
    {
        queue<t> *n = new queue<t>(d);

        if (q == NULL)
        {
            q = n;
            return;
        }
        else
        {
            queue<t> *temp = q;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }
    }
    void pop(queue<t> *&s)
    {
        if (s != NULL)
        {
            queue<t> *a = s;
            s = s->next;
            delete a;
        }
    }

    t top(queue<t> *&s)
    {

        if (s != NULL)
        {
            return s->data;
        }
        return NULL;
    }
    bool isempty(queue<t> *&s)
    {
        return s == NULL ? true : false;
    }
};

template <typename t>
class tree
{
public:
    t data;
    tree<t> *right;
    tree<t> *left;

    tree(t d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    void insert(tree<t> *&root, t d)
    {
        tree<t> *n = new tree<t>(d);
        if (root == NULL)
        {
            root = n;
            return;
        }

        queue<tree *> *q = NULL;
        q->push(q, root);

        while (!q->isempty(q))
        {
            tree<t> *f = q->top(q);
            q->pop(q);

            if (f->left == NULL)
            {
                f->left = n;
                return;
            }
            if (f->right == NULL)
            {
                f->right = n;
                return;
            }
            if (f->left)
                q->push(q, f->left);
            if (f->right)
                q->push(q, f->right);
        }
    }

    void level_order(tree<t> *root)
    {
        cout << "\nlevel order\n";
        if (root == NULL)
        {
            cout << "NULL";

            return;
        }
        queue<tree *> *q = NULL;
        q->push(q, root);
        q->push(q, NULL);
        while (!q->isempty(q))
        {
            tree<t> *f = q->top(q);
            q->pop(q);

            if (f == NULL)
            {
                if (!q->isempty(q))
                {
                    q->push(q, NULL);
                }
                cout << "\n";
            }
            else
            {
                cout << f->data << " ";

                if (f->left)
                    q->push(q, f->left);
                if (f->right)
                    q->push(q, f->right);
            }
        }
    }
    // part a
    bool search(tree<t> *root, t c)
    {
        queue<tree *> *q = NULL;
        q->push(q, root);
        while (!q->isempty(q))
        {
            tree<t> *f = q->top(q);
            q->pop(q);

            if (f->data == c)
            {
                return true;
            }

            if (f->left)
                q->push(q, f->left);
            if (f->right)
                q->push(q, f->right);
        }

        return false;
    }

    // part b

    void height(tree<t> *root, int h, int &ans, t key)
    {
        if (root == NULL)
            return;

        if (root->data == key)
        {
            ans = h;
            return;
        }

        height(root->left, h + 1, ans, key);
        height(root->right, h + 1, ans, key);
    }

    int height_of_a_given_node(tree<t> *root, t key)
    {
        int ans = -1;

        height(root, 0, ans, key);
        return ans;
    }

    // part c

    void depth(tree<t> *root, int h, int &ans, bool &c, t key)
    {
        if (root == NULL)
        {
            if (c)
            {
                c = false;
                ans = h;
            }
            return;
        }

        if (root->data == key)
        {
            c = true;
        }
        if (c)
        {
            depth(root->left, h + 1, ans, c, key);
            depth(root->right, h + 1, ans, c, key);
        }
        else
        {
            depth(root->left, 0, ans, c, key);
            depth(root->right, 0, ans, c, key);
        }
    }

    int depth_of_a_given_node(tree<t> *root, t key)
    {
        int ans = -1;
        bool c = false;
        depth(root, 0, ans, c,key);
        return ans;
    }

    // part d

    void solve(tree<t>* root,int& i)
    {
        if(root==NULL) return;

        solve(root->left,i);
        i++;
        solve(root->right,i);
    }

    int number_of_node(tree<t> * root)
    {
        int i=0;
        solve(root,i);
        return i;
    }

    bool complete_bst(tree<t> * root,int i,int n)
    {
        if(root==NULL) return true;
        if(i>=n)
        {
            return false;
        }

       return complete_bst(root->left,2*i+1,n) && complete_bst(root->right,2*i+2,n);

    }
};

int main()
{
    tree<char> *root = NULL;
    int n;
    cout << "enter the size of charater array : ";
    cin >> n;
    char arr[n];
    cout << "enter the data : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        root->insert(root, arr[i]);
    }
    root->level_order(root);

    int t;
    cout<<"enter 1 for search(0 to skip): ";
    cin>>t;
    while(t)
    {
        char c;
        cout<<"enter the key for search : ";
        cin>>c;

        if(root->search(root,c))
        {
            cout<<"the key is present .\n";

        }
        else cout<<"the key is not present .\n";

        cout<<"enter 0 to discontinue searching(any other number to continue : )";
        cin>>t;

    }

    cout<<"enter 1 for computing height of a specific node(0 to skip) : ";
    cin>>t;
    while(t)
    {
        char c;
        cout<<"enter the key for search : ";
        cin>>c;

        cout<<"the height of the given node is: "<<root->height_of_a_given_node(root,c)<<"\n";
        cout<<"enter 0 to discontinue (any other number to continue : )";
        cin>>t;

    }


    cout<<"enter 1 for computing depth of a specific node(0 to skip) : ";
    cin>>t;
    while(t)
    {
        char c;
        cout<<"enter the key for search : ";
        cin>>c;

        cout<<"the height of the given node is: "<<root->depth_of_a_given_node(root,c)<<"\n";
        cout<<"enter 0 to discontinue (any other number to continue : )";
        cin>>t;

    }

    int k=root->number_of_node(root);

    if(root->complete_bst(root,0,n))
    {
        cout<<"its a complete binary tree .";
    }
    else cout<<"its not a complete binary tree .";
}