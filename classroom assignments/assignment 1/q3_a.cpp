#include <iostream>
using namespace std;
#include <queue>
class max_heap
{
public:
    int *arr;
    int capacity;
    int size;

    max_heap(int c)
    {
        this->arr = new int[c];
        this->capacity = c;
        this->size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left_child(int i) { return (2 * i) + 1; }
    int right_child(int i) { return (2 * i) + 2; }
    void insert(int data)
    {
        if (size == capacity)
        {
            cout << "overflow \n";
            return;
        }
        arr[size] = data;

        int i = size;
        size++;
        while (i >= 1)
        {
            if (arr[parent(i)] < arr[i])
            {
                int temp = arr[parent(i)];
                arr[parent(i)] = arr[i];
                arr[i] = temp;
                i = parent(i);
            }
            else
                break;
        }
    }

    void deletion()
    {
        if (size < 0)
        {
            cout << "NOTHING TO DELETE\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while (i < size)
        {
            int largest = i;
            int l = left_child(i);
            int r = right_child(i);
            if (l < size && arr[i] < arr[l])
            {
                largest = l;
            }
            if (r < size && arr[largest] < arr[r])
            {
                largest = r;
            }
            if (largest != i)
            {
                int temp = arr[i];
                arr[i] = arr[largest];
                arr[largest] = temp;
                i = largest;
            }
            else
                return;
        }
    }

    void print()
    {
        queue<int> q;
        if (size == 0)
        {
            cout << "NULL";
            return;
        }

        q.push(0);
        q.push(-1);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            if (i == -1)
            {
                if (!q.empty())
                    q.push(-1);
                cout << "\n";
            }
            else
            {
                if (i < size)
                    cout << arr[i] << " ";
                if (left_child(i) < size)
                    q.push(left_child(i));
                if (right_child(i) < size)
                    q.push(right_child(i));
            }
        }
    }

    int max_element()
    {
        if (size >= 0)
            return arr[0];
        return -1;
    }

    void increase_key(int key, int value)
    {
        if (size < 0)
        {
            cout << "\n no element : \n ";
            return;
        }
        int i;

        for (i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                break;
            }
        }
        if (i == size)
        {
            cout << "\n key is not found : \n ";
            return;
        }
        arr[i] = key + value;

        while (i >= 1)
        {
            if (arr[parent(i)] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[parent(i)];
                arr[parent(i)] = temp;
                i = parent(i);
            }
            else
                break;
        }
    }

    void decrease_key(int key, int value)
    {
        if (size < 0)
        {
            cout << "\n no element : \n ";
            return;
        }
        int i;

        for (i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                break;
            }
        }
        if (i == size)
        {
            cout << "\n key is not found : \n ";
            return;
        }
        arr[i] = key - value;

        while (i < size)
        {
            int largest = i;
            int l = left_child(i);
            int r = right_child(i);

            if (l < size && arr[i] < arr[l])
            {
                largest = l;
            }
            if (r < size && arr[largest] < arr[r])
            {
                largest = r;
            }
            if (largest != i)
            {
                int temp = arr[i];
                arr[i] = arr[largest];
                arr[largest] = temp;
                i = largest;
            }
            else
                break;
        }
    }
};

int main()
{
    int n;
    cout << "enter capacity : ";
    cin >> n;
    max_heap *h = new max_heap(n);
    int s;

    cout << "enter data ( -1 to stop entering data) ";
    cin >> s;

    while (s != -1)
    {
        h->insert(s);
        cout << endl;
        h->print();
        cout << endl;
        cout << "enter data ( -1 to stop entering data) ";
        cin >> s;
    }
    h->print();

    cout << "enter any number for  deletion ( -1 to stop entering data) ";
    cin >> s;

    while (s != -1)
    {
        h->deletion();
        cout << endl;
        h->print();
        cout << endl;
        cout << "enter any number for  deletion ( -1 to stop entering data) ";
        cin >> s;
    }

    cout << "enter key for increasing key  ( -1 to stop entering data) ";
    cin >> s;

    while (s != -1)
    {
        int v;
        cout << "enter value to be add on : ";
        cin >> v;
        h->increase_key(s, v);
        cout << endl;
        h->print();
        cout << endl;
        cout << "enter key for increasing key  ( -1 to stop entering data) ";
        cin >> s;
    }

    cout << "enter key for decreasing key  ( -1 to stop entering data) ";
    cin >> s;

    while (s != -1)
    {
        int v;
        cout << "enter value to be subracted off : ";
        cin >> v;
        h->decrease_key(s, v);
        cout << endl;
        h->print();
        cout << endl;
        cout << "enter key for decreasing  key  ( -1 to stop entering data) ";
        cin >> s;
    }
}

// 100  10 20 30 40  50 60 70 80 90 100 110 120  130 140 150 160 -1