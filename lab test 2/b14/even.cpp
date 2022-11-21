#include <iostream>
using namespace std;

void dfs(int x, int y, int v, int &c, int **mat, int **visited)
{
    if (x < 0 || y < 0 || x >= v || y >= v || mat[x][y] == -1 || visited[x][y] == 1)
    {
        return;
    }
    if (x == v - 1 && y == v - 1)
    {
        c++;
        return;
    }
    visited[x][y] = 1;

    dfs(x, y + 1, v, c, mat, visited);
    dfs(x + 1, y, v, c, mat, visited);
    // dfs(x,y-1,v,c,mat,visited);
    // dfs(x-1,y,v,c,mat,visited);
    // dfs(x-1,y+1,v,c,mat,visited);
    // dfs(x+1,y+1,v,c,mat,visited);
    // dfs(x+1,y-1,v,c,mat,visited);
    // dfs(x-1,y-1,v,c,mat,visited);

    visited[x][y] = 0;
}

int main()
{
    int v;
    cout << "enter the number of vertices : ";
    cin >> v;
    int **mat = new int *[v];
    int **visited = new int *[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = new int[v];
        mat[i] = new int[v];
    }

    cout << "enter the maze : \n";
    for (int i = 0; i < v; i++)
    {
        cout << "enter " << i + 1 << " th row: ";
        for (int j = 0; j < v; j++)
        {
            cin >> mat[i][j];
        }
    }

    int ct = 0;

    dfs(0, 0, v, ct, mat, visited);

    cout << ct;
}