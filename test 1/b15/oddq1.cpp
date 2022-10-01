#include<iostream>
using namespace std;

/*Construct a queue data structure to store list of students (atleast 10). The student whose name
is alphabetically more should be inserted after the student whose name is alphabetically less. Write
final complexity of your designed algo.*/

class queue
{
    public: 

    string  data;
    queue * next;

    queue(string d)
    {
        this->data=d;
        this->next=NULL;
    }

    void enqueue(queue *& front, string d)
    {
        queue * n=new queue(d);

        if(front==NULL)
        {
            front=n;
            return;
        }
        else
        {
            queue  * temp=front;
            while(temp->next!=NULL && temp->next->data>d)
            {
                temp=temp->next;
            }
            n->next=temp->next;
            temp->next=n;
        }
    }

    void dequeue(queue *& front)
    {
        if(front==NULL)
        {
            return;
           
        }
        else
        {
            queue * to_del=front;
            front=front->next;
            delete(to_del);
            return;
        }
    }

    string front(queue *& front)
    {
        if(front!=NULL)
        {
            return front->data;
        }
    }

    void print (queue * & front)
    {
        queue * temp=front;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    queue * q=NULL;

    int n=10;
    for(int i=0;i<n;i++)
    {
        string s;
        cout<<" enter the data: ";
        cin>>s;

        q->enqueue(q,s);

    }

    q->print(q);
}


//time complecity of inserting is : o(n)