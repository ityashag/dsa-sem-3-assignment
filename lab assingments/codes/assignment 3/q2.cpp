#include <iostream>
using namespace std;

class book
{
public:
    string name;
    string a_name;
    int pb_year;
    int isbn;
    int copy;
    book *next;

    book(string n, string a, int py, int is, int co)
    {
        this->name = n;
        this->a_name = a;
        this->pb_year = py;
        this->isbn = is;
        this->copy = co;
        this->next = NULL;
    }
    void add(book *&head)
    {
        string n, a;
        cout << "enter the name of book : ";
        cin >> n;
        cout << "enter the author name : ";
        cin >> a;

        int p, i, c;
        cout << "enter the publication year : ";
        cin >> p;
        cout << "enter the ISBN number : ";
        cin >> i;
        cout << "enter the number of copies : ";
        cin >> c;

        book *t = new book(n, a, p, i, c);

        if (head == NULL)
        {
            head = t;
            return;
        }
        book *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = t;
    }

    void delete_node(book *&head, int is)
    {

        book *temp = head;

        if (temp->isbn == is)
        {
            head = temp->next;

            delete (temp);
            return;
        }

        while (temp->next != NULL && temp->next->isbn != is)
        {
            temp = temp->next;
        }

        if (temp->next == NULL || temp == NULL)
        {
            cout << "the isbn number is wronge.\n";
            return;
        }

        book *to_del = temp->next;
        temp->next = to_del->next;
        to_del->next = NULL;
        delete (to_del);
    }
    void update_node(book *&head, int is)
    {
        book *temp = head;

        string n, a;
        cout << "enter the updated name of book : ";
        cin >> n;
        cout << "enter the updated author name : ";
        cin >> a;

        int p, i, c;
        cout << "enter the updated publication year : ";
        cin >> p;
        cout << "enter the updated ISBN number : ";
        cin >> i;
        cout << "enter the updated number of copies : ";
        cin >> c;

        if (temp->isbn == is)
        {
            temp->name = n;
            temp->a_name = a;
            temp->copy = c;
            temp->isbn = i;
            temp->pb_year = p;
            return;
        }

        while (temp != NULL && temp->isbn != is)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "the isbn number is wronge. or not found in record : \n";
            return;
        }

        temp->name = n;
        temp->a_name = a;
        temp->copy = c;
        temp->isbn = i;
        temp->pb_year = p;
    }

    void print(book *&head)
    {

        book *temp = head;
        cout << "\nALL BOOK RECORDS \n";
        while (temp != NULL)
        {

            cout << " the name of book : " << temp->name << "\n";
            cout << " the author name : " << temp->a_name << "\n";
            cout << " the publication year : " << temp->pb_year << "\n";
            cout << " the ISBN number : " << temp->isbn << "\n";
            cout << " the number of copies : " << temp->copy << "\n\n";

            temp = temp->next;
        }
        cout << "\nend\n";
    }
};

class issue
{
public:
    string name;
    string a_name;
    issue *next;

    issue(string n, string a)
    {
        this->name = n;
        this->a_name = a;
        this->next = NULL;
    }
    void add(issue *&head)
    {
        string n, a;
        cout << "enter the name of book : ";
        cin >> n;
        cout << "enter the name of the student who had issued the book : ";
        cin >> a;

        issue *t = new issue(n, a);

        if (head == NULL)
        {
            head = t;
            return;
        }
        issue *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = t;
    }

    void delete_node(issue *&head, string is)
    {

        issue *temp = head;

        if (temp->a_name == is)
        {
            head = temp->next;

            delete (temp);
            return;
        }

        while (temp->next != NULL && temp->next->a_name != is)
        {
            temp = temp->next;
        }

        if (temp->next == NULL || temp == NULL)
        {
            cout << "the borrower name is not found in our record.\n";
            return;
        }

        issue *to_del = temp->next;
        temp->next = to_del->next;
        to_del->next = NULL;
        delete (to_del);
    }
    void update_node(issue *&head, string is)
    {
        issue *temp = head;

        string n, a;
        cout << "enter the updated name of book : ";
        cin >> n;
        cout << "enter the updated name of the borrower : ";
        cin >> a;
        if (temp->a_name == is)
        {
            temp->name = n;
            temp->a_name = a;
            return;
        }

        while (temp != NULL && temp->a_name != is)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "the borrower name is not found in our record.\n";
            return;
        }

        temp->name = n;
        temp->a_name = a;
    }

    void print(issue *&head)
    {

        issue *temp = head;
        cout << "\nALL BOOK RECORDS \n";
        while (temp != NULL)
        {

            cout << "the name of book : " << temp->name << "\n";
            cout << " borrower name : " << temp->a_name << "\n";

            temp = temp->next;
        }
        cout << "\nend\n";
    }
};

int main()
{
    int t = 1;

    book *head = NULL;
    issue *h = NULL;
    while (t)
    {

        cout << "enter 1 to add a record of book.\nenter 2 to delete a record of book\nenter 3 to update a record of books\nenter 4 to print records of books\nenter 0 to exit";
        cout << "\nenter 5 to add a record of issue .\nenter 6 to delete a record of issue\nenter 7 to update a record of issue\nenter 8 to print records of issue\n";
        cin >> t;
        switch (t)
        {
        case 1:
            head->add(head);
            break;
        case 2:
            int is;
            cout << "enter isbn number of the book to be deleted : ";
            cin >> is;
            head->delete_node(head, is);
            break;
        case 3:
            // int is;
            cout << "enter isbn number of the book to be deleted : ";
            cin >> is;
            head->update_node(head, is);
            break;
        case 4:
            head->print(head);
            break;
        case 0:
            break;
        }

        if (t == 5)
        {
            h->add(h);
        }
        else if (t == 6)
        {
            string s;
            cout << "enter name of borrower : ";
            cin >> s;
            h->delete_node(h, s);
        }
        else if (t == 7)
        {
            // int is;
            string s;
            cout << "enter name of borrower : ";
            cin >> s;
            h->update_node(h, s);
        }
        else if (t == 8)
        {
            h->print(h);
        }
    }
}
