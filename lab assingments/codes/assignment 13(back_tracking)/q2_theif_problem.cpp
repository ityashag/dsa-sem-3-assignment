#include <iostream>
// #include<limit.h>
using namespace std;

bool dfs(int nd, int t, int **temp, int visited[], int n)
{
    if (nd == t)
        return true;
    visited[nd] = 1;

    for (int i = 0; i < n; i++)
    {
        if (temp[nd][i] && !visited[i])
        {
            if (dfs(i, t, temp, visited, n))
                return true;
        }
    }
    visited[nd] = 0;
    return false;
}

int main()
{
    int n;
    cout << "enter the number of edges : ";
    cin >> n;

    int e;
    cout << "enter the number of edges : ";
    cin >> e;

    int **mat = new int *[n];

    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cout << "enter the edges a-b : ";
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    int **temp = new int *[n];

    for (int i = 0; i < n; i++)
    {
        temp[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = 0;

    int ans = 10000000;

    for (int i = 1; i < n - 1; i++)
    {

        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                temp[l][k] = mat[l][k];
            }
        }

        for (int j = i; j < n - 1; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp[j][k] = 0;
                temp[k][j] = 0;
            }
            // for (int k = 0; k < n; k++)
            // {
            //     for (int l = 0; l < n; l++)
            //     {
            //         cout<<temp[k][l]<<" ";
            //     }
            //     cout<<endl;
            // }

            int visited[n];
            for (int i = 0; i < n; i++)
                visited[i] = 0;

            if (!dfs(0, n - 1, temp, visited, n))
            {
                //cout << j << " " << 0 << " " << i << endl;
                ans = min(ans, j - i+1);
            }
        }
    }

    if(ans == 10000000)
    {
        cout<<"\ntheif will reach the destination . ";
    }
    else

    cout << "\nneed to block min : " << ans << " vetices . ";
} // 14 24 0 1 0 2 0 3 0 4 1 5 2 5 3 5 4 5 1 6 4 7 5 6 5 7 6 8 7 8 8 9 8 10 8 11 8 12 12 7 9 6 13 9 13 10 13 11 13 12 
  // 5 6 0 1 0 2 0 3 1 4 2 4 3 4