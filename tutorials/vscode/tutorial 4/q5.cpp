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
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void print(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    int n;
    int m;
    cout << "enter the length of link list 1 : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        head1->create(head1);
    }

    cout << "enter the length of link list 2 : ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        head2->create(head2);
    }

    head1->print(head1);
    head2->print(head2);

    node *head3 = NULL;

    if (head1->data < head2->data)
    {
        head3 = head1;
        head1 = head1->next;
    }
    else
    {
        head3 = head2;
        head2 = head2->next;
    }
    node *temp = head3;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
            temp=temp->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
            temp=temp->next;
        }
    }
 

    if(head1!=NULL && head2==NULL)
    {
        while(head1!=NULL)
        {
            temp->next = head1;
            head1 = head1->next;
            temp=temp->next;
        }

    }
    else if(head2!=NULL && head1==NULL)
    {
         while(head2!=NULL)
        {
            temp->next = head2;
            head2 = head2->next;
            temp=temp->next;
        }

    }

head3->print(head3);
}