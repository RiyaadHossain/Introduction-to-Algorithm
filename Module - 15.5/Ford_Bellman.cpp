#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, ll>;

const int N = 101;
ll cost[N];

void initAuxArr(int n)
{
    for (int i = 1; i <= n; i++)
        cost[i] = 30000;
}

void printShortestPath(vector<pair<int, pi>> edges, int n)
{
    initAuxArr(n);

    cost[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            int w = edges[j].first;
            if (cost[u] < 30000 && cost[u] + w < cost[v])
                cost[v] = cost[u] + w;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << cost[i] << " ";
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, pi>> edges;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    printShortestPath(edges, n);

    return 0;
}