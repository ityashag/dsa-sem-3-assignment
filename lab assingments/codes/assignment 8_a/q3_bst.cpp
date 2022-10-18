#include <iostream>
#include <vector>
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
    void push(queue<t> *&s, t d)
    {
        queue<t> *n = new queue<t>(d);

        if (s == NULL)
        {
            s = n;
            return;
        }
        else
        {
            queue<t> *temp = s;
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
            queue<t> *to = s;
            s = s->next;
            delete to;
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
    bool isempty(queue<t> *s)
    {
        return s == NULL ? true : false;
    }
};

class bst
{

    void solve(bst *root, int &ans)
    {
        if (root == NULL)
            return;

        ans++;
        solve(root->left, ans);
        solve(root->right, ans);
    }
    void solve1(bst *root, int &ans)
    {
        if (root == NULL)
            return;

        ans += root->data;
        solve1(root->left, ans);
        solve1(root->right, ans);
    }

    int balance_factor(bst *root)
    {
        if (root == NULL)
            return -1;

        return 1 + balance_factor(root->left) + balance_factor(root->right);
    }

    void avl(bst *root, bool &c)
    {
        if (root == NULL)
        {
            return;
        }

        avl(root->left, c);

        if (balance_factor(root) < -1 || balance_factor(root) > 1)
        {
            c = false;
            return;
        }
        avl(root->right, c);
    }

    void convert(bst *&root, int &s)
    {
        if (root == NULL)
            return;
        convert(root->right, s);
        s += root->data;
        root->data = s - root->data;
        convert(root->left, s);
    }

public:
    int data;
    bst *right;
    bst *left;

    bst(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }

    bst *insert_into_bst(bst *root, int d)
    {
        if (root == NULL)
        {
            bst *n = new bst(d);
            return n;
        }
        if (root->data < d)
        {
            root->right = insert_into_bst(root->right, d);
        }
        else
        {
            root->left = insert_into_bst(root->left, d);
        }
        return root;
    }

    void insert(bst *&root)
    {
        int d;
        cout << "enter the data: (-1 to stop) ";
        cin >> d;

        while (d != -1)
        {
            root = insert_into_bst(root, d);
            cout << "enter the data: (-1 to stop) ";
            cin >> d;
        }
    }

    void inorder(bst *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }

    void level_order(bst *&root)
    {
        if (root == NULL)
        {
            cout << "NULL";
            return;
        }
        queue<bst *> *q = NULL;

        q->push(q, root);
        q->push(q, NULL);
        while (!q->isempty(q))
        {
            bst *f = q->top(q);
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
                {
                    q->push(q, f->left);
                }
                if (f->right)
                {
                    q->push(q, f->right);
                }
            }
        }
    }

    // part a

    int number_of_node(bst *root)
    {
        int ans = 0;
        solve(root, ans);

        return ans;
    }

    // part b

    int weight(bst *root)
    {
        int ans = 0;
        solve1(root, ans);

        return ans;
    }

    // part d

    bool check_avl(bst *root)
    {
        bool c = true;

        avl(root, c);

        return c;
    }

    // part e

    void convert_into_greater_bst(bst *&root)
    {

        int s = 0;
        convert(root, s);
        return;
    }
};

int main()
{
    bst *root = NULL;

    root->insert(root);

    cout << "inorder:" << endl;
    root->inorder(root);

    cout << "\nnumber of nodes : " << root->number_of_node(root);
    cout << "\nweight of tree : " << root->weight(root);
    if (root->check_avl(root))
    {
        cout << "\nthe tree is avl .";
    }
    else
        cout << "\nthe tree is not avl.";

    cout << "\n";

    root->convert_into_greater_bst(root);
    cout << "inorder:" << endl;
    root->inorder(root);
}