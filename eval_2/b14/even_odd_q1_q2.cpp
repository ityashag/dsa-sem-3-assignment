// pre 12 7 5 10 21 15
// in 5 7 10 12 15 21


// pre 10 20 40 50 30 60
// in 40 20 50 10 60 30
#include<iostream>
using namespace std;
template<typename t>
class queue
{
    public:
    t data;
    queue<t>  *next;

    queue(t d)
    {
        this->data=d;
        this->next=NULL;
    }

    void push(queue <t>*  &q,t d)
    {
        queue<t> * n = new queue <t> (d);

        if(q==NULL)
        {
            q=n;
            return;

        }
        else
        {
            queue<t> * temp=q;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
        }

    }
    void pop(queue<t> * & q)
    {
        if(q!=NULL)
        {
            queue<t>  * to=q;
            q=q->next;
            delete to;
        }
    }

    t top(queue<t> * & q)
    {
        if(q!=NULL)
        {
            return q->data ;
        }
        return NULL;
    }

    bool isempty(queue<t> * & q)
    {
        return q==NULL ? true : false; 
    }

    

};



class node 
{
    public: 
    int data;
    node *left;
    node * right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

    void inorder(node * root)
    {
        if(root==NULL) return ;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void deletion_deepest(node*& root)
    {
        if(root==NULL) return;
        queue<node *> *q=NULL;
        q->push(q,root);
       node * deepest=NULL;

        while(!q->isempty(q))
        {
            node * f=q->top(q);
            q->pop(q);

            deepest=f;

            if(f->left) q->push(q,f->left);
            if(f->right) q->push(q,f->right);
        }

        if(root==deepest)
        {
            root=NULL;
            return;
        }

        q->push(q,root);

        while(!q->isempty(q))
        {
            node * f=q->top(q);
            q->pop(q);

            if(f->left) {
                if(f->left==deepest)
                {
                    f->left=NULL;
                    delete deepest;
                    return;
                }
               else  q->push(q,f->left);}
            if(f->right){ 
                if(f->right==deepest)
                {
                    f->right=NULL;
                    delete deepest;
                    return;
                }
                else q->push(q,f->right);}

        }
        
    

    }


    void insert_at_last(node* & root,int d)
    {
        if(root==NULL){root=new node(d); return ;}
        queue<node *> * q=NULL;
        q->push(q,root);
       node * deepest=NULL;

        while(!q->isempty(q))
        {
            node * f=q->top(q);
            q->pop(q);

            deepest=f;

            if(f->left) q->push(q,f->left);
            if(f->right) q->push(q,f->right);
        }

        deepest->left=new node(d);

    }


    void level_order(node * root)
    {
         if(root==NULL) return;
        queue<node *> *q=NULL;
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

            if(f->left) q->push(q,f->left);
            if(f->right) q->push(q,f->right);
           }
        }
    }

};

int search_in(int in[],int s,int e,int key)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==key) return i;
    }
    return -1;
}

node * construct_from_in_pre(int in[] ,int pre[],int & i,int s,int e)
{

    if(s>e) return NULL;

    node * root = new node (pre[i++]);
    if(s==e) return root;

    int index=search_in(in,s,e,root->data);

    root->left=construct_from_in_pre(in , pre,i,s,index-1);
    root->right=construct_from_in_pre(in,pre,i,index+1,e);
    return root;
}
int main()
{
    int n;
    cout<<"enter the number of nodes : ";
    cin>>n;

    int in[n],pre[n];

    cout<<"enter the data in preorder : ";
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }

    cout<<"enter the data in inorder : ";
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }

    int i=0;

    node * root = construct_from_in_pre(in,pre,i,0,n-1);

    root->inorder(root);

    for(int i=0;i<2;i++)
    {
        cout<<endl;
        root->deletion_deepest(root);
        root->level_order(root);
    }

    for(int i=0;i<2;i++)
    {
        int key;

        cout<<"enter the data for insertion : ";
        cin>> key;
        root->insert_at_last(root,key);
        cout<<endl;
         root->level_order(root);
    }
}


// int main()
// {
//     queue<int> * q=NULL;


//     for(int i=0;i<10;i++)
//     {
//         q->push(q,i+1);

//     }

//     while(!q->isempty(q))
//     {
//         cout<<q->top(q);
//         q->pop(q);
//     }
// }