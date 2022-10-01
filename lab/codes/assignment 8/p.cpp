/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class node
{

public:
    int data;
    node *next;
    node *prev;
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
        else
        {
            node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
            n->prev = temp;
        }
    }

    void insert_at_position(node *&head, int d, int pos)
    {
        node *n = new node(d);
        if (pos == 1)
        {
            n->next = head;
            head->prev = n;
            head = n;
            return;
        }
        else
        {
            int c = 1;
            node *temp = head;
            while (temp != NULL && c < pos)
            {
                temp = temp->next;

                c++;
            }
            if (temp == NULL || c == pos)
            {
                head->create(head, d);

                return;
            }
            else
            {
                n->next = temp->next;
                n->prev = temp;
                temp->next = n;
                n->next->prev = n;
            }
        }
    }

    void delete_at_position(node *&head, int pos)
    {
        node *to_del = head;
        if(head->next==NULL)
        {
            head=NULL;
            return;
        }
        if (pos == 1)
        {
            head = head->next;
            head->prev = NULL;
            delete to_del;

            return;
        }
        else
        {
            int c = 1;
            node *temp = head;
            while (temp != NULL && c < pos)
            {
                temp = temp->next;
                c++;
            }

            if (temp == NULL || c==pos)
            {
                temp = head;
                while (temp ->next!= NULL )
                {
                    temp = temp->next;
                }
                temp=temp->prev;
                to_del=temp->next;
                temp->next=NULL;
                delete(to_del) ;
            }
            else
            {

                to_del = temp->next;

                temp->next = to_del->next;
                if (to_del->next != NULL)
                    to_del->next->prev = temp;
                delete (to_del);
            }
        }
    }


    node * reverse_next(node * & head)
    {
        if( head==NULL || head->next==NULL  ) return head;

        node* ch = reverse_next(head->next);
        head->next->next=head;
        head->next=NULL;
        return ch;

    }
    
    void reverse(node *& head)
    {
        head=head->reverse_next(head);

        node * prev=NULL;
        node * curr=head;
        node* next=NULL;
        while(curr!=NULL)
        {
            next=curr->prev;
            curr->prev=prev;
            prev=curr;
            curr=next;
        }
        curr=prev;
        cout<<endl;
        cout<<"NULL<=>";
        while(curr!=NULL)
        {
            cout<<curr->data<<"<=>";
            curr=curr->prev;
        }
        cout<<"NULL";
        head->print(head);
    }

    void print(node *&head)
    {
        node *temp = head;

        cout << "\nNULL<=>";
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        head->create(head, i + 1);
    }
    head->print(head);
    head->insert_at_position(head, 99, 1);
    head->print(head);
    head->insert_at_position(head, 91, 6);
    head->print(head);
    head->insert_at_position(head, 92, 3);
    head->print(head);
    head->insert_at_position(head, 93, 5);
    head->print(head);
   
   head->reverse(head);
}