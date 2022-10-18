#include<iostream> 
using namespace std;
#include<vector>

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
    
    node *insert_into_bst(node *root, int d)
    {
        if (root == NULL)
            return new node(d);
        if (d < root->data)
            root->left = insert_into_bst(root->left, d);
        else if (d > root->data)
            root->right = insert_into_bst(root->right, d);
        else
        {
            cout << "\nduplicate data\n";
            return NULL;
        }
        return root;
    }
    void   insert(node * &root)
    {
         int d;
        cout << "enter the data (-1 to end) : ";
        cin >> d;
        while (d != -1)
        {
            root = insert_into_bst(root, d);
            cout << "enter the data (-1 to end) : ";
            cin >> d;
        }
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


    void inorder(node * root ,vector<int> & a)
    {
        if(root==NULL)
        {
            return;
        }

        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);

    }


};

int main()
{

    node * root1=NULL;
    cout<<"insert in bst 1 : \n";
    root1->insert(root1);

    cout<<"\n level order bst 1 : \n";
    root1->level_order(root1);


    node * root2=NULL;
    cout<<"insert in bst 2 : \n";
    root2->insert(root2);

    cout<<"\n level order bst 2 : \n";
    root2->level_order(root2);

    vector<int> a1;
    vector<int> a2;

    root1->inorder(root1,a1);
    root2->inorder(root2,a2);




    vector<int> ans(a1.size()+a2.size());

    int m=max(a1[a1.size()-1],a2[a2.size()-1])+1;


    a1.push_back(m);
    a2.push_back(m);

    int k=0;
    int i=0;
    int j=0;

    while(k<a1.size()+a2.size()-2)
    {
        
        if(a1[i]<a2[j]) ans[k++]=a1[i++];
        else ans[k++]=a2[j++];
        cout<<ans[k-1]<<" ";

    }

    cout<<"\nmerge sorted array : ";

    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }








}

//  5 3 6 2 4 -1

//  2 1 3 7 6 -1