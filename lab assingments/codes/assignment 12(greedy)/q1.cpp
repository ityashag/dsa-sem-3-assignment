#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int total_distance;
    int m;
    int n;
    

    cout<<"enter the total distance between Akshardham and JIIT - 62 : ";
    cin>>total_distance;
    cout<<"enter the value of m : ";
    cin>>m;
    cout<<"enter the number of pumps : ";
    cin>>n;
    int pumps[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the distance of pump "<<i+1<<" from the akarshardham : ";
        cin>>pumps[i];
    }

    int current_distance=0;
    int fuel=m;
    int number_of_pump=0;
    int next_stop=0;
    vector<int> stops;
    int current_stop=-1;
    while(current_distance!=total_distance)
    {
        next_stop=current_stop+1;
        while(next_stop<n && pumps[next_stop]-current_distance<=m)
        {
            next_stop++;
        }

        //next_stop--;
        stops.push_back(next_stop);
        current_stop=next_stop;
        current_distance=pumps[next_stop];
        
    }
    cout<<"\n stops at : ";
    for(int i=0;i<stops.size();i++)
    {
        cout<<stops[i]<<" ";
    }

}

// 10 2 10 1 2 3 4 5 6 7 8 9 10