
#include <iostream>
using namespace std;

class node
{
public:
    string source;
    string destination;
    int flight_no;
    node *next;

    node(string s,string d,int f)
    {
        this->source = s;
        this->destination = d;
        this->flight_no= f;
        this->next = NULL;
    }
    void insert(node *&s, string m, string d,int f)
    {
        node *n = new node(m, d, f);

        if (s == NULL)
        {
            s = n;
            return;
        }
        else
        {
            node *temp = s;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }
    }

    void print(node *&s)
    {
        node *temp = s;
        while (temp != NULL)
        {
            cout<<"flight no : "<<temp->flight_no<<" source : "<<temp->source<<" destination "<<temp->destination<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    node * n1=NULL;

    int n;
    cout<<"enter the length : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        string m;
        string d;
        int f;
         cout<<"enter source : ";
         cin>>m;
         cout<<"enter destination : ";
         cin>>d;
         cout<<"enter flight _ no : ";
         cin>>f;

        n1->insert(n1,m,d,f);
        
    }

    cout<<endl;

    n1->print(n1);
}