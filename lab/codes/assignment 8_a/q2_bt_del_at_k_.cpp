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

class tree
{
public:
    int data;
    tree *left;
    tree *right;

    tree(int d)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
    }

    tree *insert(tree *root)
    {
        int d;
        cout << "enter the data (-1 for NULL) : ";
        cin >> d;
        if (d == -1)
        {
            return NULL;
        }
        root = new tree(d);

        cout << "for the left of  " << d << " ";
        root->left = insert(root->left);
        cout << "for the right of " << d << " ";
        root->right = insert(root->right);
        return root;
    }

    void delete_deepest(tree *&root, tree *temp)
    {
        queue<tree *> *q = NULL;

        if (root == temp && root->left == NULL && root->right == NULL)
        {
            root = NULL;
            return;
        }

        q->push(q, root);
        while (!q->isempty(q))
        {
            tree *f = q->top(q);
            q->pop(q);

            if (f == temp)
            {
                delete temp;
                return;
            }
            if (f->left)
            {
                if (f->left == temp)
                {
                    f->left = NULL;
                    delete temp;
                    return;
                }
                else
                    q->push(q, f->left);
            }
            if (f->right)
            {
                if (f->right == temp)
                {
                    f->right = NULL;
                    delete temp;
                    return;
                }
                else
                    q->push(q, f->right);
            }
        }
    }

    void del(tree *&root, int key)
    {
        if (root->data == key && root->left == NULL && root->right == NULL)
        {
            root = NULL;
            return;
        }
        tree *target = NULL;
        tree *deepest = NULL;

        queue<tree *> *q = NULL;

        q->push(q, root);
        while (!q->isempty(q))
        {
            tree *f = q->top(q);
            q->pop(q);

            if (f->data == key)
            {
                target = f;
            }
            deepest = f;
            if (f->left)
            {
                q->push(q, f->left);
            }
            if (f->right)
            {
                q->push(q, f->right);
            }
        }

        if (target == NULL)
        {
            cout << "key is not present \n";
            return;
        }

        if (target == deepest)
        {
            delete_deepest(root, target);
            return;
        }

        int x = deepest->data;
        delete_deepest(root, deepest);
        if (root == NULL)
            return;
        target->data = x;
    }

    void level_order(tree *&root)
    {
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
            tree *f = q->top(q);
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

    void del_k(tree * & root,int k)
    {
        if(root==NULL) return;
        queue<tree *> *q = NULL;
        q->push(q, root);
        vector<int> a;
        q->push(q, NULL);
        int c=0;
        while (!q->isempty(q))
        {
            tree *f = q->top(q);
            q->pop(q);

            if (f == NULL)
            {
                if (!q->isempty(q))
                {
                    q->push(q, NULL);
                }
                c++;
            }
            else
            {
                if(c==k)
                {
                    a.push_back(f->data);

                }
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

        for(int i=0;i<a.size();i++)
        {
            root->del(root,a[i]);
        }
        
    }

    void find_n(tree * root, tree * & t, int key)
    {
        if(root==NULL)
        {
            return;

        }
        if(root->data==key)
        {
            t=root;
            return;

        }
        find_n(root->left,t,key);
        find_n(root->right,t,key);

    }

    tree * find_node(tree * root,int key)
    {
        tree * ans=NULL;
        find_n(root,ans,key);

        return ans;

    }
};

int main()
{

    tree *root = NULL;
    root = root->insert(root);
    cout << "\n level order: \n";
    root->level_order(root);

    int t;

    cout << "enter the data of the nodes whoese subtree wants to display (-1 to discontinue ) ";
    cin>>t;
    while (t != -1)
    {
        tree * f=root->find_node(root,t);
        if(f!=NULL)
        {
        cout << "\n level order of a paricular subtree : \n";
        root->level_order(f);
        }
        else cout<<"\nthe node is not present .";
        cout << "\nenter the data of the nodes whoese subtree wants to display (-1 to discontinue ) ";
        cin>>t;
    }


    cout << "enter the data for delete (-1 to discontinue ) ";
    cin>>t;
    while (t != -1)
    {
        root->del(root, t);

        cout << "\n level order after deletion : \n";
        root->level_order(root);
        cout << "\nenter the data for delete (-1 to discontinue ) ";
        cin>>t;
    }

    cout << "enter the of the level whose all nodes to be deleted (-1 to discontinue ) ";
    cin>>t;
    while(t!=-1 && root!=NULL)
    {
        root->del_k(root, t);

        cout << "\n level order after deletion : \n";
        root->level_order(root);
        cout << "\nenter the value of level (-1 to discontinue ) ";
        cin>>t;

    }
    if(root==NULL)
    {
        cout<<"ALL ELEMENTS ARE DELETED .";
    }

}

// 4 3 5 -1 -1 -1 6 7 -1 -1 8 -1 -1