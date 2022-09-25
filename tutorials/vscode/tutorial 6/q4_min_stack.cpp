
#include<string>
#include <iostream>

using namespace std;

template <typename t>
class stack
{
public:
    t data;
    static int min;
    stack *next;

    stack(t d)
    {
        this->data = d;
        this->next = NULL;
    }


    void print(stack<t> *&top)
    {
        cout<<"stack :\n";
        stack <t> * temp=top;
        cout<<"top-> ";
        if(top==NULL)return;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    

    void push(stack<t> *&top, t d)
    {
        stack<t> *n = new stack<t>(d);
     
        if (top == NULL)
        {
            min=d;
            top = n;
            return;
        }

        if(d<min)
        {
            // data = 2* current mini(d)- previous mini  (mn)
            n->data=((2*n->data)-min);
            //updata min;
            min=d;
        }
        n->next = top;
        top = n;
    }


    t tos(stack<t> *&top)
    {
        if (top == NULL)
            return -1;
        else
            return (top->data<min)?min:top->data; //important 
    }

    t pop(stack<t> *&top)
    {
        if (top == NULL)
            return -1;
        int a = top->data;
        stack<t> *to_delete = top;
        top = top->next;

        if(a<min)
        {
            int y=min;

            min = 2*min - a;
            a=min;

        }
        delete (to_delete);
        return a;
    }

    int minimun_element(stack*& s)
    {
        return min;
    }

    bool isempty(stack *&top)
    {
        if(top == NULL) return 1;
        else return 0;
    }
};
template <typename t>
int stack<t>::min=10000007;


int main()
{
    cout<<rand()/10000;

    stack<int> * s=NULL;
    s->push(s,3);
    s->push(s,5);
    s->push(s,2);
    s->push(s,1);
    s->push(s,1);
    s->push(s,-1);

    
    s->print(s);

    while(!s->isempty(s))
    {
        cout<<s->tos(s)<<endl;
        cout<<" minimun element "<<s->minimun_element(s)<<" \n";
        s->pop(s);
    }
   
}