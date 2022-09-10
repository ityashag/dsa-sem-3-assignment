#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    static int mi;

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
            mi = d;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        mi = max(mi, d);
        temp->next = n;
        n->prev = temp;
    }
    int max_element(node *&head)
    {
        if (head == NULL)
        {
            return -1;
        }
        return mi;
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
};

int node::mi = INT_MIN;

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
    cout << "max element : ";
    cout << head->max_element(head);
}
