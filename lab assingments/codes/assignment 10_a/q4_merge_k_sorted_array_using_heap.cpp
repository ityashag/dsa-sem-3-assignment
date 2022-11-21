#include <iostream>
using namespace std;

class min_heap
{
public:
    int *arr;
    int capacity;
    int size;

    min_heap(int c)
    {
        this->arr = new int[c];
        this->capacity = c;
        this->size = 0;
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

    void print()
    {
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
};

int main()
{

    
    int n,k;
    cout<<"enter the values of k and n : ";
    cin>>k>>n;
    min_heap *h = new min_heap(n*k +1);

    for(int i=0;i<k;i++)
    {
        cout<<"\nenter "<<i+1<<" th sorted array  : ";
        for(int j=0;j<n;j++)
        {
            int d;
            cin>>d;
            h->insert(d);
        }
    }

    cout<<"merged k sorted arrays : ";
    for(int i=0;i<n*k;i++)
    {
        int d= h->extract_min();
        cout<<d<<" ";
    }



}

//5 5   
//1 2 3 4 5 
//6 7 8 9 10 
//60 70 80 90 100 
//20 30 40 50 51 
//66 67 68 69 71