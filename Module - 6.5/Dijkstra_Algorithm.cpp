#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];
    
    while (e--)
    {
          int a, b,c;
       cin >> a >> b >> c;
       graph[a].push_back(b);
       graph[b].push_back(a); // For Undirected graph
    }
   
    return 0;
}