#include<iostream> 
using namespace std;

template<typename t>
class queue
{

    public: 
    t data;
    queue<t> * next;
    queue(t d)
    {
        this->data=d;
        this->next=NULL;
    }

    void push(queue<t> * & r, t d)
    {
        queue<t> * n=new queue<t> (d);
        if(r==NULL)
        {
            r=n;
            return ;
        }
        queue<t> * temp=r;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=n;
        return;

    }

    void pop(queue<t> * &r)
    {
        if(r!=NULL) 
        {
            queue <t> * to=r;
            r=r->next;
            delete to;
        }
    }

    t top(queue<t> * & r)
    {
        if(r!=NULL) return r->data;

        return 0;

    }
    bool  isempty(queue<t> * &r)
    {
        return r==NULL ?true: false;
    }

};


class node
{
    public:
    node *left;
    node * right;
    int data;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
    node *  insert()
    {
        int d;
        cout<<"enter the data :(-1 for NULL) ";
        cin>>d;

        if(d==-1) return NULL;

        node * root=new node (d);

        cout<<"for the left of "<<d<<" ";
        root->left=insert();
        cout<<"for the right of "<<d<<" ";
        root->right=insert();
        return root;
    }

    void level_order(node * root)
    {
        queue<node *> * q=NULL;
        q->push(q,root);
        q->push(q,NULL);

        while(!q->isempty(q))
        {
            node * f=q->top(q);
            q->pop(q);

            if(f==NULL)
            {
                if(!q->isempty(q))
                {
                    q->push(q,NULL);

                }
                cout<<endl;

            }
            else
            {
                cout<<f->data<<" ";
                if(f->left)
                {
                    q->push(q,f->left);
                }
                if(f->right)
                {
                    q->push(q,f->right);

                }

            }
        }

    }


    void mirror(node* & root)
    {
        if(root==NULL) return;
        node * temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }


};

int main()
{

    node * root=NULL;

    root=root->insert();

    cout<<"\n level order : \n";
    root->level_order(root);

    cout<<"\nlevel order of mirror tree : \n";
    root->mirror(root);
    root->level_order(root);



}

//  1 3 -1 -1 2 5 -1 -1 4 -1 -1