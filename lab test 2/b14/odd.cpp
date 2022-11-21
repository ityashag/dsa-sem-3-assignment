#include<iostream>
using namespace std;

int main()
{
    int v,e;
    cout<<"enter the number of vertices and edges : ";
    cin>>v>>e;

    int mat[v+1][v+1];
    for(int i=0;i<v+1;i++)
    {
        for(int j=0;j<v+1;j++)
        {
            mat[i][j]=0;
        }
    }

    int parent[v+1];
    int children[v+1];
    for(int i=0;i<v+1;i++)
    {
        parent[i]=0;
        children[i]=0;
    }

    for(int i=0;i<e;i++)
    {
        cout<<"enter a->b ";
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;
    }

   



    for(int i=1;i<v+1;i++)
    {
        int ct=0;
        for(int j=1;j<v+1;j++)
        {
            if(mat[i][j]==1)
            {
                ct++;
                parent[j]++;
            }
            
        }
        children[i]=ct;
    }

   

    

    int kk=0;
    for(int i=1;i<=v;i++)
    {
        if(children[i]>parent[i] && parent[i]!=0)
        {
            kk++;
        }
    }

    cout<<kk;




}