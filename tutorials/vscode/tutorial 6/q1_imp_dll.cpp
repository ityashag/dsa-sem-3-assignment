#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    void create(node *&head, int d)
    {
        node *n = new node(d);

        if (head == NULL)
        {
            head = n;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    void print(node *&head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void del(node *&head)
    {
        int d;
        cout << "enter the data to delete : ";
        cin >> d;

        if (head == NULL)
        {
            cout << "empty list ";
            return;
        }
        if (head->data == d)
        {
            node *to = head;
            head = head->next;
            delete (to);
            head->prev = NULL;
            return;
        }
        node *temp = head;
        while (temp->next != NULL && temp->next->data != d)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "data is not found in list \n";
            return;
        }

        node *to = temp->next;
        temp->next = to->next;
        if (to->next != NULL)
            to->next->prev = temp;
        delete (to);
    }
};

int main()
{
    int n;
    cout << "enter the size of doubly link list : ";
    cin >> n;
    node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int d;
        cout << "enter the data ";
        cin >> d;

        head->create(head, d);
    }
    head->print(head);
    while (n)
    {
        head->del(head);
        cout << "continue to 1 else 0 ";
        cin >> n;
        head->print(head);
    }
}
