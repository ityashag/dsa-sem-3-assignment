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

    void pop(queue<t> *&q)
    {
        if (q != NULL)
        {
            queue<t> *n = q;
            q = q->next;
            delete n;
        }
    }
    t top(queue<t> *s)
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

class node
{

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

    int get_balance_factor(node *root)
    {
        if (root == NULL)
            return -1;
        return height_c(root->left) - height_c(root->right);
    }

    node *left_r(node *x)
    {
        node *y = x->left;
        node *b = y->right;
        y->right = x;
        x->left = b;
        return y;
    }

    node *right_r(node *x)
    {
        node *y = x->right;
        node *b = y->left;
        y->left = x;
        x->right = b;
        return y;
    }

    int min_value(node *root)
    {
        node *r = root->right;
        while (r->left != NULL)
            r = r->left;

        return r->data;
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
    int height_c(node *root)
    {

        int ans = 0;
        height_cal(root, 0, ans);
        return ans;
    }

    node *insert_into_avl(node *&root, int d)
    {
        if (root == NULL)
        {
            return new node(d);
        }
        if (root->data < d)
        {
            root->right = insert_into_avl(root->right, d);
        }
        else if (root->data > d)
        {
            root->left = insert_into_avl(root->left, d);
        }
        else
        {
            cout << "\nduplicate data .\n ";
            return root;
        }

        int bf = get_balance_factor(root);

        if (bf > 1 && get_balance_factor(root->left) >= 0)
        {
            return left_r(root);
        }
        if (bf > 1 && get_balance_factor(root->left) < 0)
        {
            root->left = right_r(root->left);
            return left_r(root);
        }
        if (bf < -1 && get_balance_factor(root->right) <= 0)
        {
            return right_r(root);
        }
        if (bf < -1 && get_balance_factor(root->right) > 0)
        {
            root->right = left_r(root->right);
            return right_r(root);
        }
        return root;
    }

    node *delete_form_avl(node *&root, int key)
    {
        if (root == NULL)
            return root;
        // if(root->data==key && root->left==NULL && root->right==NULL) return NULL;

        if (root->data < key)
        {
            root->right = delete_form_avl(root->right, key);
        }
        else if (root->data > key)
        {
            root->left = delete_form_avl(root->left, key);
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
                node *b = root->left;
                delete root;
                return b;
            }
            else if (root->left != NULL && root->right != NULL)
            {
                int miniv = min_value(root);
                root->data = miniv;
                root->right = delete_form_avl(root->right, miniv);
            }
        }
        if (root == NULL)
            return root;

        int bf = get_balance_factor(root);
        if (bf > 1 && get_balance_factor(root->left) >= 0)
        {
            return left_r(root);
        }
        if (bf > 1 && get_balance_factor(root->left) < 0)
        {
            root->left = right_r(root->left);
            return left_r(root);
        }

        if (bf < -1 && get_balance_factor(root->right) <= 0)
        {
            return right_r(root);
        }
        if (bf < -1 && get_balance_factor(root->right) > 0)
        {
            root->right = left_r(root->right);
            return right_r(root);
        }
        return root;
    }

    void level_order(node *&root)
    {
        if (root == NULL)
        {
            cout << "NULL";
            return;
        }
        queue<node *> *q = NULL;
        q->push(q, root);
        q->push(q, NULL);

        while (!q->isempty(q))
        {
            node *f = q->top(q);
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

    void inorder(node *&root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    node *root = NULL;

    cout << "enter the data to insert into avl (-1 to exit): ";
    int d;
    cin >> d;

    while (d != -1)
    {

        root = root->insert_into_avl(root, d);
        cout << "enter the data to insert into avl (-1 to exit): ";
        cin >> d;
    }
    cout << "\nlevel order :\n";
    root->level_order(root);

    int key;

    cout << "enter the key for deletion (-1 to exit):";
    cin >> key;

    while (key != -1)
    {

        root = root->delete_form_avl(root, key);

        cout << "\nalter deletion :level order :\n";
        root->level_order(root);
        cout << "enter the key for deletion (-1 to exit):";
        cin >> key;
    }
}

// 12 23 16 49 34 42 45 -1