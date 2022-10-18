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
            return;
        }
    }

    void pop(queue<t> *&q)
    {
        if (q != NULL)
        {
            queue<t> *te = q;
            q = q->next;

            delete te;
        }
    }

    t top(queue<t> *&q)
    {
        if (q != NULL)
        {
            return q->data;
        }
        return NULL;
    }

    bool isempty(queue<t> *&q)
    {
        return q == NULL ? true : false;
    }
};

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

    void height(node *root , int h,int & ans)
    {
        if(root==NULL) {ans=max(ans,h); return ;}

        height(root->left,h+1,ans);
        height(root->right,h+1,ans);
    }

    int height_cal(node * root)
    {
        int ans=0;
        height(root,0,ans);
        return ans;

    }

    int get_balance_factor(node * root)
    {
        if(root==NULL) return -1;
        return height_cal(root->left)-height_cal(root->right);

    }

    node * left_r(node * x)
    {
        node * y=x->left;
        node * b=y->right;
        y->right=x;
        x->left=b;
        return y;

    }

    node * right_r(node * x)
    {
        node * y=x->right;
        node * b=y->left;
        y->left=x;
        x->right=b;
        return y;

    }

   

    node *insert_into_avl(node *root, int data)
    {
        if (root == NULL)
            return new node(data);
        if (root->data < data)
        {
            root->right = insert_into_avl(root->right, data);
        }
        else if (root->data > data)
        {
            root->left = insert_into_avl(root->left, data);
        }
        else
        {
            cout << "\nduplicate data .\n";
            return root;
        }

        int bf=get_balance_factor(root);

        if(bf>1 && get_balance_factor(root->left)>=0)
        {
            return left_r(root);

        }
        if(bf>1 && get_balance_factor(root->left)<0)
        {
            root->left=right_r(root->left);
            return left_r(root);
            
        }
        if(bf<-1 && get_balance_factor(root->right)<=0)
        {
            return right_r(root);
            
        }
        if(bf<-1 && get_balance_factor(root->right)>0)
        {
            root->right=left_r(root->right);
            return right_r(root);
            
        }

        return root;


    }
    void inorder(node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void insert(node *&root)
    {
        int data;
        cout << "enter the data : (-1 to stop) ";
        cin >> data;
        while (data != -1)
        {
            root = insert_into_avl(root, data);
            cout << "enter the data : (-1 to stop) ";
            cin >> data;
        }
    }

    void level_order(node *root)
    {
        if (root == NULL)
        {
            cout << "\nNULL";
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
    int min_value(node *root)
    {
        node *r = root->right;
        while (r->left != NULL)
        {
            r = r->left;
        }
        return r->data;
    }

    node *deletion(node *  root, int d)
    {
        if (root == NULL)
            return NULL;

        if (root->data < d)
            root->right = deletion(root->right, d);
        else if (root->data > d)
            root->left = deletion(root->left, d);
        else if(root->data==d)
        {
            if (root->left == NULL)
            {
                node *a = root->right;
                delete root;
                return a;
            }
            else if (root->right == NULL)
            {
                node *a = root->left;
                delete root;
                return a;
            }
            else if (root->right != NULL && root->left != NULL)
            {

                int x = min_value(root);
                root->data = x;
                root->right = deletion(root->right, x);
                //return root;
            }
        }

        if(root==NULL)  return root;

        int bf=get_balance_factor(root);

        if(bf>1 && get_balance_factor(root->left)>=0)
        {
            return left_r(root);

        }
        if(bf>1 && get_balance_factor(root->left)<0)
        {
            root->left=right_r(root->left);
            return left_r(root);
            
        }
        if(bf<-1 && get_balance_factor(root->right)<=0)
        {
            return right_r(root);
            
        }
        if(bf<-1 && get_balance_factor(root->right)>0)
        {
            root->right=left_r(root->right);
            return right_r(root);
            
        }

        return root;
    }


};

int main()
{

    // queue<int> *q = NULL;
    // for (int i = 0; i < 10; i++)
    // {
    //     q->push(q, i + 1);
    // }
    // while (!q->isempty(q))
    // {
    //     cout << q->top(q);
    //     q->pop(q);
    // }

    node *root = NULL;
    root->insert(root);
    cout << "\nlevel order \n";
    root->level_order(root);

    int data;
    cout << "\nenter the data for deletion  : (-1 to stop) ";
    cin >> data;
    while (data != -1)
    {
        root = root->deletion(root, data);

        cout << "\nlevel order after deletion :\n";
    root->level_order(root);
        cout << "\nenter the data for deletion  : (-1 to stop) ";
        cin >> data;
    }
}