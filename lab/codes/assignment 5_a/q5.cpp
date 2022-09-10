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
    void del(node *&head, int d)
    {
        node *temp = head;
        if (head->data == d)
        {
            while (temp->next != head)
            {
                temp=temp->next;
            }
            
            head=head->next;
            node* to=temp->next;
            temp->next=head;
            delete(to);

            return;
        }
        while (temp->next != head)
        {
            if (temp->next->data == d)
            {
                temp->next = temp->next->next;
                cout << "deleted";
                return;
            }
            temp=temp->next;
        }

        cout<<"element is not found " ;

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
};
int main()
{
    node *head = NULL;
    int n;
    cout << "enter the length of the link list : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        head->create(head);
    }
    cout << "link list: ";
    head->print(head);
    int d;
    cout<<"enter the value to be deleted :";
    cin>>d;
    head->del(head,d);
    head->print(head);
}