#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename t>
class node
{
public:
    t data;
    node *next;
    node(t d)
    {
        this->data = d;
        this->next = NULL;
    }

    void create(node<t> *&head)
    {
        t v;
        cout << "enter the value : ";
        cin >> v;
        node<t> *n = new node<t>(v);
        if (head == NULL)
        {
            head = n;
            return;
        }

        node<t> *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
    }
    void print(node<t> *&head)
    {

        node<t> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    void bubble_Sort(node<t> *&head)
    {
        // bubble sort
        node<int> *i = head;
        while (i != NULL)
        {
            node<int> *j = head;
            while (j->next != NULL)
            {
                if (j->data > j->next->data)
                {
                    node<int> *temp = new node<int>(j->data);
                    j->data = j->next->data;
                    j->next->data = temp->data;
                }
                j = j->next;
            }
            i = i->next;
            // head->print(head);
        }
        head->print(head);
    }

    void selection_sort(node<t> *&head)
    {
        node<int> *i = head;
        while (i != NULL)
        {
            node<int> *j = i;
            node<int> *y = new node<int>(INT_MAX);
            while (j != NULL)
            {
                if (j->data < y->data)
                {
                    y = j;
                }
                j = j->next;
            }

            node<int> *temp = new node<int>(y->data);
            y->data = i->data;
            i->data = temp->data;
            delete temp;
            i = i->next;
        }

        head->print(head);
    }

    void isort(node<t> * & i,node<t> * & j, t & temp,node <t> * & pos)
    {
        if(j==i)
        {
            return;
        }
        isort(i,j->next,temp,pos);

        if(j->data>temp )
        {
            j->next->data=j->data;
        }
        else if(pos==NULL)
        {
            pos=j->next;
        }
    }



    void insertion(node<t> * & head)
    {
        node<t> * i=head->next;

        while(i!=NULL)
        {
            t temp=i->data;
            node<t> * j=head;
            node<t> * pos=NULL;

            isort(i,j,temp,pos);
            if(pos!=NULL) pos->data=temp;
            else j->data=temp;
            i=i->next;
        }
    }
};

int main()
{
    node<int> *head = NULL;
    int n;
    cout << "enter the length of link list : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        head->create(head);
    }



     //head->bubble_Sort(head);


    // head->selection_sort(head);

    head->insertion(head);

    head->print(head);
}
