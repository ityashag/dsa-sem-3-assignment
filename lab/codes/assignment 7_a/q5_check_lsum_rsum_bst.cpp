
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
            return s->data;
        return NULL;
    }

    bool isempty(queue<t> *&q)
    {
        return q == NULL ? true : false;
    }
};

class bst
{
public:
    int data;
    bst *right;
    bst *left;
    bst(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    bst *insert_into_bst(bst *root, int d)
    {
        if (root == NULL)
        {
            root = new bst(d);
            return root;
        }
        if (d > root->data)
        {
            root->right = insert_into_bst(root->right, d);
        }
        else
        {
            root->left = insert_into_bst(root->left, d);
        }
    }

    void insert(bst *&root)
    {
        int d;
        cout << "enter the data (-1 to exit) : ";
        cin >> d;
        while (d != -1)
        {
            root = insert_into_bst(root, d);
            cout << "enter the data (-1 to exit) : ";
            cin >> d;
        }
    }

    void level_order(bst *root)
    {
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
                cout << endl;
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

    //subtree 

    void find_node(bst * root, bst * & t, int d)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->data==d) {t=root; return;}
        find_node(root->left,t,d);
        find_node(root->right,t,d);
    }


    int sum (bst * root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int l=sum(root->left);
        int r=sum(root->right);

        return root->data+l+r;
    }

    void solve(bst * root)
    {
        cout<<"enter the value of node for the calculation of left and right subtree sum: ";
        int d;
        cin>>d;
        bst * target=NULL;
        find_node(root,target,d);

        int l = sum(root->left);
        int r = sum(root->right);
        if(l==r )
        {
            cout<<"sum of all the nodes of right subtree of "<<d<<" is equal then the sum of all nodes left subtree .\n";
        }
        else if(l>r)
        {
            cout<<"sum of all the nodes of right subtree of "<<d<<" is less then the sum of all nodes left subtree .\n";
        }
        else
        {
            cout<<"sum of all the nodes of right subtree of "<<d<<" is greater then the sum of all nodes left subtree .\n";
        }
        

    }
};

int main()
{

    bst * root=NULL;
    root->insert(root);
    root->level_order(root);
    cout<<endl;
    root->solve(root);
}



  