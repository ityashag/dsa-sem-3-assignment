#include <iostream>
using namespace std;

void heapify(int arr[], int i, int n)
{

    int lr = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[lr] < arr[l])
    {
        lr = l;
    }
    if (r < n && arr[lr] < arr[r])
    {
        lr = r;
    }
    if (lr != i)
    {
        int t = arr[lr];
        arr[lr] = arr[i];
        arr[i] = t;
        heapify(arr, lr, n);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, 0, i);
    }
}

int main()
{
    int n;
    cout << "enter the size of array : ";
    cin >> n;

    int arr[n];
    cout << "enter value in array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\ninitial array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    heap_sort(arr, n);
    cout << "\nsorted array : ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//A stable sorting algorithm ensures that items that are equal to each other aren't reordered during the sorting process.
//it is not the stable algorithm
//Heap sort is a comparison-based sorting technique based on Binary Heap data structure. 
//It is similar to the selection sort 
//where we first find the minimum element and place the minimum element at the beginning. 
//Repeat the same process for the remaining elements. 
//Heap sort is an in-place algorithm.