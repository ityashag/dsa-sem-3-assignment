#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    void create(node *&head)
    {
        int d;
        cout << "enter the data : ";
        cin >> d;

        node *n = new node(d);

        if (head == NULL)
        {
            n->next = n;
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }

    int size(node *&head)
    {
        node *temp = head;
        if (head == NULL)
            return 0;
        int c = 1;

        while (temp->next != head)
        {
            c++;
            temp = temp->next;
        }

        return c;
    }
    void print(node *&head)
    {
        node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << "->";
    }

    void solve(node *&head)
    {
        int n = head->size(head);
        if (n < 7)
        {
            while (head->size(head) != 7)
            {
                if (n == 0)
                    return;
                int c = 1;
                node *temp = head;
                node *ne = new node(0);
                while (c < (n - 2 + 1))
                { 
                    c++;
                    temp = temp->next;
                }
                ne->next = temp->next;
                temp->next = ne;
    
            }
             head->print(head);
        }
        else if(n>7)
        {

            node * temp=head->next;
            int c=1;
            while(c<7)
            {
                cout<<temp->data<<" ";
                c++;
                temp=temp->next;
            }
            cout<<endl;

        }
        else
        {
            head->print(head);
        }
    }
};
int main()
{
    node *head = NULL;
    int n;
    cout<<"enter the length of the link list : ";
    cin>>n;

    for (int i = 0; i <n; i++)
    {
        head->create(head);
    }
    cout<<"link list: ";
    head->print(head);
    cout<<"\n";
    head->solve(head);
    cout<<" \n";
}