#include <iostream>
#include <vector>
using namespace std;
class student
{
public:
    string name;
    long long unsigned int enroll;
    int marks[5];
    void input()
    {
        string n;
        cout << "enter name : ";
        fflush(stdin);
        getline(cin, n);
        fflush(stdin);
        name = n;
        cout << "enter enrollment number : ";
        cin >> enroll;
        cout << "enter the marks of 5 subs : ";
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }
    void detail()
    {

        cout << "NAME : " << name << "\n";
        cout << "ENROLLMENT NO : " << enroll << "\n";

        cout << " MARKS : ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\n";
    }
};


void change ( string s)
{
    cout<<s<<" : ";
    char a=s[0];

    for(int i=0;i<s.length()-1;i++)
    {
        s[i]=s[i+1];
    }
    s[s.length()-1]=a;
    s+="ay";

    s[0]=('A'+(s[0]-'a'));

    cout<<s<<"\n";


}
int main()
{
    int n;
    cout << "enter n : ";
    cin >> n;
    student s[n];

    int t = 1;
    while (t)
    {
        cout << "enter 0 to exit\n";
        cout << "enter 1 to input\n";
        cout << "enter 2 to sort by name \n";
        cout << "enter 3 to sort by enrollment number \n";
        cout << "enter 4 to sort by subject marks \n";
        cout << "enter your choice : ";
        cin >> t;

        switch (t)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                s[i].input();
            }
            break;
        case 2:
            cout << "\n\nsorted by name \n";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].name > s[j + 1].name)
                    {
                        swap(s[j], s[j + 1]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                s[i].detail();
            }
            break;

        case 3:
            cout << "\n\nsorted by enrollment  \n";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].enroll > s[j + 1].enroll)
                    {
                        swap(s[j], s[j + 1]);
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                s[i].detail();
            }
            break;
        case 4:
            cout << "\n\nsorted by marks of subject 1  \n";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].marks[0] > s[j + 1].marks[0])
                    {
                        swap(s[j], s[j + 1]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                s[n - 1 - i].detail();
            }

            cout << "\n\nsorted by marks of subject 2  \n";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].marks[1] > s[j + 1].marks[1])
                    {
                        swap(s[j], s[j + 1]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                s[n - 1 - i].detail();
            }

            cout << "\n\nsorted by marks of subject 3  \n";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].marks[2] > s[j + 1].marks[2])
                    {
                        swap(s[j], s[j + 1]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                s[n - 1 - i].detail();
            }

            cout << "\n\nsorted by marks of subject 4  \n";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].marks[3] > s[j + 1].marks[3])
                    {
                        swap(s[j], s[j + 1]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                s[n - 1 - i].detail();
            }

            cout << "\n\nsorted by marks of subject 5  \n";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].marks[4] > s[j + 1].marks[4])
                    {
                        swap(s[j], s[j + 1]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                s[n - 1 - i].detail();
            }
            break;
        }
    }



    cout<<"PIGLATIN : \n";


    for(int i=0;i<n;i++)
    {
        change(s[i].name);
    }
}