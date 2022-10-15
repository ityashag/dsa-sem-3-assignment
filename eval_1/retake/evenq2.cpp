
#include <iostream>
using namespace std;

class node
{
public:
    string medicine_name;
    int diseases_treated;
    float medicine_cost;
    node *next;

    node(string n, int d, float c)
    {
        this->medicine_name = n;
        this->diseases_treated = d;
        this->medicine_cost = c;
        this->next = NULL;
    }
    void insert(node *&s, string m, int d, float c)
    {
        node *n = new node(m, d, c);

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
            cout<<"medicine name : "<<temp->medicine_name<<" disease_treated : "<<temp->diseases_treated<<" medicine_cost "<<temp->medicine_cost<<endl;
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
        int d;
        float c;
         cout<<"enter medicine name : ";
         cin>>m;
         cout<<"enter disease_treated : ";
         cin>>d;
         cout<<"enter  medicine_cost : ";
         cin>>c;

        n1->insert(n1,m,d,c);
        
    }

    cout<<endl;

    n1->print(n1);
}