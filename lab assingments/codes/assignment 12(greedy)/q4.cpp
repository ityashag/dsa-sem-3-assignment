#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m;
    cout << "enter the capacity (m) : ";
    cin >> m;
    int n;
    cout << "enter the number of petrol pump : ";
    cin >> n;
    int arr[n];
    cout << "enter the distance of pump ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cur_dist = 0;

    vector<int> ans;
    int i;
    for (i = 0; i < n; i++)
    {

        while (i < n && arr[i] - cur_dist <= m)
        {
            i++;
        

        i--;
        ans.push_back(arr[i]);
        if (i < n)
            cur_dist = ans[i];
        if (i >= n - 2)
            break;
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << " " << ans[i];
    }
}
}