#include <iostream>
#include <vector>
#include <algorithm>

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

    node *insert_into_avl(node *root, int d)
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
            // cout<<"\nduplicate data .\n ";
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
    int height_c(node *root)
    {

        int ans = 0;
        height_cal(root, 0, ans);
        return ans;
    }

    void level_order(node *root)
    {
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

    void inorder(node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    node *convert_to_avl(node *root)
    {

        if (root == NULL)
            return NULL;
        root->left = convert_to_avl(root->left);
        root->right = convert_to_avl(root->right);

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

    void collect_data(node *root, vector<int> &a)
    {
        if (root == NULL)
        {
            return;
        }

        collect_data(root->left, a);
        a.push_back(root->data);
        collect_data(root->right, a);
    }
};

int main()
{
    node *root1 = NULL;

    cout << "enter the data to insert into avl1(-1 to exit): ";
    int d;
    cin >> d;

    while (d != -1)
    {

        root1 = root1->insert_into_avl(root1, d);
        cout << "enter the data to insert into avl1(-1 to exit): ";
        cin >> d;
    }
    cout << "\nlevel order avl 1 :\n";
    root1->level_order(root1);

    node *root2 = NULL;

    cout << "enter the data to insert into avl2(-1 to exit): ";
    cin >> d;

    while (d != -1)
    {

        root2 = root2->insert_into_avl(root2, d);
        cout << "enter the data to insert into avl2(-1 to exit): ";
        cin >> d;
    }
    cout << "\nlevel order avl 2 :\n";
    root2->level_order(root2);

    vector<int> a;

    root1->collect_data(root1, a);
    root2->collect_data(root2, a);

    node *root3 = NULL;

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        root3 = root3->insert_into_avl(root3, a[i]);
    }

    cout << "\nresultant avl : ";
    cout << "\nlevel order:\n";
    root3->level_order(root3);
}
// 13 10 15 5 11 14 16 4 6 -1
// 33 13 53 11 21 61 8 9 -1