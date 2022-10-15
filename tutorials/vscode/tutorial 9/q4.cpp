#include<iostream>
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
    public: 
    int data;
    node * left;
    node * right;
    node(int d)
    {
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
    node * insert_into_bst(node * root,int d)
    {
        if(root==NULL) return new node(d);
        if(root->data < d)
        {
            root->right=insert_into_bst(root->right,d);
        }
        else if (root->data >d)
        {
            root->left=insert_into_bst(root->left,d);

        }
        return root;
    }
    void insert(node * & root)
    {
        int d;
        cout<<"enter the data (-1 NULL): ";
        cin>>d;

        while(d!=-1)
        {
            root=insert_into_bst(root,d);
            cout<<"enter the data (-1 NULL): ";
            cin>>d;

        }
    }

    void preorder(node * root)
    {
        if(root==NULL) return ;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }

    int min_value(node * root)
    {
        node * r=root->right;

        while(r->left!=NULL)
        {
            r=r->left;
        }
        return r->data;
    }
    node * deletion(node * root, int d)
    {
        if(root==NULL) return NULL;
        if(root->data < d)
        {
            root->right=deletion(root->right,d);
        }
        else if(root->data > d)
        {
            root->left=deletion(root->left,d);
        }
        else
        {
            if(root->left==NULL)
            {
                node * a =root->right;
                delete root;
                return a;

            }
            else if(root->right==NULL)
            {
                node * a =root->left;
                delete root;
                return a;
            }
            else if(root->right!=NULL && root->left!=NULL)
            {
                int x=min_value(root);
                //cout<<"\n*"<<x<<"\n";
                root->data=x;
                root->right=deletion(root->right,x);
                return root;
            }
        }
       
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

     void height_cal(node * root,int h,int  & ans)
    {
        if(root==NULL){ans=max(h,ans); return;}
        height_cal(root->left,h+1,ans);
        height_cal(root->right,h+1,ans);
    }

    int height_c(node * root)
    {
        int ans=0;
        height_cal(root,0,ans);
        return ans;
    }

    int get_balance_factor(node * root)
    {
        if(root==NULL) return -1;
        return height_c(root->left)-height_c(root->right);
    }

    void check(node * root, bool & c)
    {
        if(root==NULL) return;

        if(get_balance_factor(root)<-1 || get_balance_factor(root)>1  ){c=false; return;}
        if(root->left!=NULL && root->data<root->left->data){c=false; return;};
        if(root->right!=NULL && root->data>root->right->data){c=true; return;};
        check(root->right,c);
        check(root->left,c);

    }


    bool check_avl(node * root)
    {
        bool c=true;
        check(root,c);
        return c;
    }

};
int main()
{
    node * root =NULL;
    root->insert(root);
    cout<<"\nlevel order : \n";
    root->level_order(root);
    cout<<"\n";

    if(root->check_avl(root))
    {
        cout<<"\nthis bst is avl";

    }
    else
    {
        cout<<"\nthis bst is not avl";
    }

}
//  10 2030, 25, 15, 5, 35, 45, 55, 50, 45, 40



