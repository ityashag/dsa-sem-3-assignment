#include <iostream>

using namespace std;

template <typename t>
class queue
{
public:
    t data;
    queue *next;
    queue(t d)
    {
        this->next = NULL;
        this->data = d;
    }

    void push(queue *&front, queue *&rear, t d)
    {
        queue *n = new queue(d);
        if (front == NULL)
        {
            front = n;
            rear = n;
            return;
        }
        else
        {
            rear->next = n;
            rear = rear->next;
        }
    }
    void pop(queue *&front, queue *&rear)
    {
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            queue *to_del = front;
            front = front->next;
            delete (to_del);
        }
    }

    bool isempty(queue *front)
    {
        return front == NULL ? true : false;
    }

    t front(queue *&front)
    {
        if (front != NULL)
        {
            return front->data;
        }
    }
};

// bst
class bst
{
public:
    int data;
    bst *left;
    bst *right;

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
            bst *n = new bst(d);
            return n;
        }
        if (root->data < d)
        {
            root->right = insert_into_bst(root->right, d);
        }
        else
        {
            root->left = insert_into_bst(root->left, d);
        }

        return root;
    }

    void create(bst *&root)
    {
        cout << " enter the data : (0 to exit ) : ";
        int d;
        cin >> d;

        while (d)
        {
            root = root->insert_into_bst(root, d);
            cout << " enter the data : (0 to exit ) : ";
            cin >> d;
        }
    }

    void inorder(bst *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void search(bst * root ,bst* & parent ,bool & flag,int key)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->data==key)
        {
            flag=true;
            return;

        }
        else if(root->left!=NULL&&root->left->data==key)
        {
            flag=true;
            parent=root;
            return ;

        }
        else if(root->right!=NULL&&root->right->data==key)
        {
            flag=true;
            parent=root;
            return;
        }

        search(root->left,parent,flag,key);
        search(root->right,parent,flag,key);
    }

    void level_order(bst *root)
    {

        queue<bst *> *qf = NULL;
        queue<bst *> *qr = NULL;

        qf->push(qf, qr, root);
        qf->push(qf, qr, NULL);

        while (!qf->isempty(qf))
        {
            bst *front = qf->front(qf);
            qf->pop(qf, qr);

            if (front == NULL)
            {
                if (!qf->isempty(qf))
                {
                    qf->push(qf, qr, NULL);
                }
                cout << endl;
            }
            else
            {
                cout<<front->data<<" ";

                if (front->left)
                {
                    qf->push(qf, qr, front->left);
                }
                if (front->right)
                {
                    qf->push(qf, qr, front->right);
                }
            }
        }
    }
};

int main()
{
    bst *root = NULL;

    root->create(root);

    cout<<"\n enter data to search : ";
    int d;
    cin>>d;
    bool flag=false;
    bst * parent =NULL;
    root->search(root,parent,flag,d);

    if(flag)
    {
        if(parent==NULL)
        {
            cout<<"root is key :";

        }
        else
        {
            cout<<"parent : "<<parent->data;
        }
    }
    else
    {
        cout<<"data is not found ";
    }




    
}