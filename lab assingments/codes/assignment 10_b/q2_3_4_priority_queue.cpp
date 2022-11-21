#include <iostream>
using namespace std;

class piority_heap
{
public:
    int *arr;
    int capacity;
    int size;

    piority_heap(int c)
    {
        this->arr = new int[c];
        this->capacity = c;
        this->size = 0;
    }

    void heapify(int arr[], int i, int n)
    {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[smallest] > arr[l])
        {
            smallest = l;
        }
        if (r < n && arr[smallest] > arr[r])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            int t = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = t;
            heapify(arr, smallest, n);
        }
    }

    void shift_up(int arr[], int i)
    {
        if (i>0)
        {
            if (arr[i] < arr[i / 2])
            {
                int t = arr[i];
                arr[i] = arr[i / 2];
                arr[i / 2] = t;
                shift_up(arr, i/2);
            }
        }
    }
    void insert(int d)
    {
        if (size == capacity)
        {
            cout << "overflow\n";
            return;
        }
        arr[size] = d;
        
        int i = size;
        size++;
        shift_up(arr, i);
    }

    void del(int d)
    {
        if (size <= 0)
        {
            cout << "underflow\n";
            return;
        }
        int i;
        for (i = 0; i < size; i++)
        {
            if (arr[i] == d)
            {
                break;
            }
        }
        if (i == size)
        {
            cout << "not found data in heap\n";
            return;
        }

        int t = arr[i];
        arr[i] = arr[size - 1];
        arr[size - 1] = t;

        size--;

        heapify(arr, i, size);
    }

    int extract_min()
    {
        if (size <= 0)
        {
            cout << "underflow\n";
            return -1;
        }
        int i = 0;
        int ans = arr[i];

        int t = arr[i];
        arr[i] = arr[size - 1];
        arr[size - 1] = t;

        size--;

        heapify(arr, i, size);
        return ans;
    }

    int find_max()
    {
        if (size <= 0)
        {
            cout << "underflow\n";
            return -1;
        }
        int ans = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[ans] < arr[i])
            {
                ans = i;
            }
        }
        return arr[ans];
    }

    void change(int old_value, int new_value)
    {

        if (size <= 0)
        {
            cout << "underflow\n";
            return;
        }
        int i;
        for (i = 0; i < size; i++)
        {
            if (arr[i] == old_value)
            {
                break;
            }
        }
        if (i == size)
        {
            cout << "not found data in heap\n";
            return;
        }
        if (arr[i] > new_value)
        {
            arr[i] = new_value;
            shift_up(arr, i);
        }
        else
        {
            arr[i] = new_value;
            heapify(arr, i, size);
        }
    }

    void print()
    {
        cout << "\nmin heap : ";
        if (size <= 0)
        {
            cout << "empty";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    int c;
    cout << "enter the capacity of min heap : ";
    cin >> c;

    piority_heap *h = new piority_heap(c);

    int d;
    cout << "enter the value of data to insert in heap  (-1 for stop) : ";
    cin >> d;
    while (d != -1)
    {
        h->insert(d);
        h->print();
        cout << "\nenter the value of data to insert in heap  (-1 for stop) : ";
        cin >> d;
    }

    cout << "enter the value of data to delete in heap  (-1 for stop) : ";
    cin >> d;
    while (d != -1)
    {
        h->del(d);
        h->print();
        cout << "\nenter the value of data to delete in heap  (-1 for stop) : ";
        cin >> d;
    }

    cout << "enter the value of data for change value in heap  (-1 for stop) : ";
    cin >> d;
    while (d != -1)
    {
        int k;
        cout<<"enter the new value : ";
        cin>>k;
        h->change(d,k);
        h->print();
        cout << "\nenter the value of data for change value in heap  (-1 for stop) : ";
        cin >> d;
    }

    cout<<"max_element : "<<h->find_max();
    cout<<"\nextraxt_min : "<<h->extract_min();
    h->print();
}