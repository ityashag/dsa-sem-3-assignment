#include<iostream>
#include<limits.h>
using namespace std;

//implementation of dijkstra algorithm

class pr
{
    public:
    int key;
    int value;
};
class priority_queue
{
    public: 
    pr *arr;
    int capacity;
    int size;

    priority_queue(int c)
    {
        this->arr = new pr [c];
        this->capacity = c;
        this->size = 0;
    }

    void heapify(pr * arr, int i, int n)
    {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[smallest].key > arr[l].key)
        {
            smallest = l;
        }
        if (r < n && arr[smallest].key > arr[r].key)
        {
            smallest = r;
        }
        if (smallest != i)
        {
            pr t = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = t;
            heapify(arr, smallest, n);
        }
    }

    void shift_up(pr arr[], int i)
    {
        if (i>0)
        {
            if (arr[i].key < arr[i / 2].key)
            {
                pr t = arr[i];
                arr[i] = arr[i / 2];
                arr[i / 2] = t;
                shift_up(arr, i/2);
            }
        }
    }
    void insert( int key,int value)
    {
        if (size == capacity)
        {
            cout << "overflow\n";
            return;
        }
        arr[size].key= key;
        arr[size].value=value;

        
        int i = size;
        size++;
        shift_up(arr, i);
    }

    void del(int d)
    {
        if (size <= 0)
        {
            cout << "underflow\n";
            return;
        }
        int i;
        for (i = 0; i < size; i++)
        {
            if (arr[i].key == d)
            {
                break;
            }
        }
        if (i == size)
        {
            cout << "not found data in heap\n";
            return;
        }

        pr t = arr[i];
        arr[i] = arr[size - 1];
        arr[size - 1] = t;

        size--;

        heapify(arr, i, size);
    }

    pr extract_min()
    {
        int i = 0;
        pr ans = arr[i];

        pr t = arr[i];
        arr[i] = arr[size - 1];
        arr[size - 1] = t;

        size--;

        heapify(arr, i, size);
        return ans;
    }

    bool isempty()
    {
        return size<=0 ? true: false;
    }
};


class node 
{
    public:
    int n;
    int w;
    node * next;

    void push(node * & h ,int n ,int w)
    {
        node * ne = new node ;
        ne->n=n;
        ne->w=w;
        ne->next=NULL;
        if(h==NULL)
        {
            h=ne;
        }
        else
        {
            node * t=h;
            while(t->next!=NULL) t=t->next;
            t->next=ne;
        }

    }

};

int main()
{
    int v;
    cout<<"enter the number of vertices in a direct graph : ";
    cin>>v;

    int e;
    cout<<"enter the number of edges in a direct graph : ";
    cin>>e;

    node ** head = new node * [v];

    for(int i=0;i<v;i++)
    {
        head[i]=NULL;
    }

    for(int i=0;i<e;i++)
    {
        cout<<"enter a->b and weight  ";
        int a,b,w;
        cin>>a>>b>>w;
        head[a]->push(head[a],b,w);
    }

    int s;
    cout<<"enter the source node : ";
    cin>>s;



    int ans[v];
    
    for(int i=0;i<v;i++)
    {
        ans[i]=INT_MAX;
    }

    ans[s]=0;

    priority_queue * q = new priority_queue(1000);
    q->insert(s,ans[s]);

    while(!q->isempty())
    {
        pr top =q->extract_min();
        int w,a;
        w=top.key;
        a=top.value;

        node * t= head[a];
        while(t!=NULL)
        {
            if(ans[t->n] > w+t->w)
            {
                ans[t->n]=w+t->w;
                q->insert(t->n,ans[t->n]);
            }
            t=t->next;
        }
    }

    cout<<"\nanswer : ";

    for(int i=0;i<v;i++)
    {
        if(ans[i]!=INT_MAX)
        cout<<ans[i]<<" ";
        else
        {
            cout<<char(236)<<" ";
        }

    }


}

