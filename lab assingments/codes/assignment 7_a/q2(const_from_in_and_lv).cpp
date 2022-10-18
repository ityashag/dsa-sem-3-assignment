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

    void push(queue<t> * &s,t d)
    {
        queue<t> * n=new queue<t> (d);

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

    void pop(queue<t> * &s)
    {
        if(s!=NULL)
        {
            queue<t> * to=s;
            s=s->next;
            delete to;
        }
    }

    t top(queue<t> *& s)
    {
        if(s!=NULL)
        {
            return s->data;
        }
        return NULL;
    }

    bool isempty(queue<t> *&s)
    {
        return s==NULL ?  true : false;
    }


};


class tree
{
    public:
    int data;
    tree * left;;
    tree * right;

    tree(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

    void level_order(tree  * root)
    {
        queue<tree *> *q=NULL;
        q->push(q,root);
        q->push(q,NULL);
        while(!q->isempty(q))
        {
            tree  * f=q->top(q);
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

int search(int in[],int s,int e,int key)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==key) return i;
    }
    return -1;
}

int * const_lv(int in[],int s,int e,int lv[],int n)
{
    int * ans=new int [e-s+1];
    int k=0;

    for(int i=0;i<n;i++)
    {
        if(search(in,s,e,lv[i])!=-1) ans[k++]=lv[i];
    }
    return ans;

}



tree * const_bt(int in[],int s,int e,int n, int lv[])
{

    if(s>e) return NULL;

    tree * root = new tree(lv[0]);
    if(s==e) return root;

    int index=search(in,s,e,lv[0]);

    int *ll=const_lv(in,s,index-1,lv,n);
    int *rl=const_lv(in,index+1,e,lv,n);
    root->left=const_bt(in,s,index-1,index-s,ll);
    root->right=const_bt(in,index+1,e,e-index,rl);
    return root;



}

int main()
{
    int n;
    cout<<"enter the lenght of the inorder or levelorder array : ";
    cin>>n;
    int in[n],lv[n];
    

    cout<<"enter the inorder : ";

    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }

    cout<<"\nenter the  levelorder :  ";
    for(int i=0;i<n;i++)
    {
        cin>>lv[i];
    }

    tree  * root= const_bt(in,0,n-1,n,lv);
    root->level_order(root);

    
}