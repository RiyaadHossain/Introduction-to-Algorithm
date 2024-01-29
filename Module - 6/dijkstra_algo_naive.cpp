#include <bits/stdc++.h>
using namespace std;
using PairInt = pair<int, int>;

const int N = 10e3;
vector<PairInt> adj[N];
int dis[N];

void dijkstra(int src)
{
    queue<PairInt> qu;
    qu.push({src, 0});
    dis[0] = 0;

    while (!qu.empty())
    {
        PairInt parent = qu.front();
        qu.pop();

        int node = parent.first;
        int cost = parent.second;

        for (auto child : adj[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            int totalCost = cost + childCost;
            if (totalCost < dis[childNode])
            {
                dis[childNode] = totalCost;
                qu.push({childNode, totalCost});
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 0; i < v; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    for (int i = 0; i < v; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}