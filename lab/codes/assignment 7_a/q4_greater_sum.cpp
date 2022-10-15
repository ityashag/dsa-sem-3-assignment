#include <iostream>

using namespace std;

template<typename t>
class queue
{
    public :
    t data;
    queue<t>  * next;
    queue(t d)
    {
        this->data=d;
        this->next=NULL;
    }

    void push(queue<t> * & s,t d)
    {
        queue<t> * n =new queue<t> (d);

        if(s==NULL)
        {
            s=n;
            return;

        }
        else
        {

            queue<t> * temp=s;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;

        }

    }

    void pop(queue<t> * & s)
    {
        if(s!=NULL)
        {
            queue<t> *to=s;
            s=s->next;
            delete to;
        }
    }

    t top(queue<t> *  &s)
    {
        if(s!=NULL) return s->data;
        return NULL;

    }

    bool isempty(queue<t> *& q)
    {
        return q==NULL ?true : false;
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
        this->right = NULL;
        this->left = NULL;
    }

    // tree * insert(tree * root)
    // {
    //     cout<<"enter the data : (-1 fot NULL) ";
    //     int d;
    //     cin>>d;

    //     if(d==-1) return NULL;

    //     root=new tree (d);

    //     cout<<"for the left of "<<d<<" ";
    //     root->left=insert(root->left);

    //     cout<<"for the right of "<<d<<" ";
    //     root->right=insert(root->right);
    // }

    void insert_into_bst(bst * & root,int d)
    {
        bst * temp=root;

        while(temp)
        {
            if(temp->data==d) {cout<<"\nduplicate data : "; return;}
            if(temp->left)
            {
                if(temp->data>d)
                {
                    temp=temp->left;
                    continue;
                }
            }
            if(temp->left==NULL)
            {
                if(temp->data>d)
                {
                    bst * n=new bst(d);
                    temp->left=n;
                    return;
                }
            }
            if(temp->right)
            {
                if(temp->data<d)
                {
                    temp=temp->right;
                    continue;
                }
            }
            if(temp->right==NULL)
            {
                if(temp->data<d)
                {
                    bst * n=new bst(d);
                    temp->right=n;
                    return;
                }
            }
        }
    }

    void insert(bst *&root)
    {
        cout << "enter the data : (-1 fot NULL) ";
        int d;
        cin >> d;
        if(d==-1) {return;}

        root=new bst (d);
        while(d!=-1)
        {
            cout << "enter the data : (-1 fot NULL) ";
            int d;
            cin >> d;
            if(d==-1) return;

            insert_into_bst(root,d);
            

        }
    }

    void level_order(bst * root)
    {
        queue<bst *> * q=NULL;
        q->push(q,root);
        q->push(q,NULL);
        while(!q->isempty(q))
        {
            bst * f= q->top(q);
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

    void inorder(bst * root)
    {
        if(root==NULL) return ;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }

    // greater sum function
    void solve(bst * root, int & sum)
    {
        if(root==NULL)
        {
            return;
        }
        
        solve(root->right,sum);
        sum+=root->data;
        root->data=sum-root->data;
        solve(root->left,sum);

    }

    void greater_sum(bst *& root)
    {
        int sum=0;
        solve(root , sum);
        return ;


    }
};

int main()
{
    // queue<int> * q= NULL;

    // for(int i=0;i<10;i++)
    // {
    //     q->push(q,i+1);
    // }
    // while(!q->isempty(q))
    // {
    //     cout<<q->top(q)<<endl;
    //     q->pop(q);
    // }

    bst * root=NULL;
    root->insert(root);
    //root->inorder(root);
    root->level_order(root);

    cout<<endl;
    root-> greater_sum(root);
    root->level_order(root);


}