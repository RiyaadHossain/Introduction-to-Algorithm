#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3;
int vis[N];

void dijkstra(vector<vector<pair<int, int>>> adj, int src, ll dis[])
{
    dis[src] = 0;

    queue<pair<int, ll>> qu;
    qu.push({src, 0});

    while (!qu.empty())
    {
        pair<int, ll> u = qu.front();
        qu.pop();

        int node = u.first;
        ll cost = u.second;

        for (auto ch : adj[node])
        {
            ll totalCost = cost + ch.second;
            if (totalCost < dis[ch.first])
            {
                dis[ch.first] = totalCost;
                qu.push({ch.first, totalCost});
            }
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n + 1);

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    int src;
    cin >> src;

    ll dis[n + 1];
    for (int i = 1; i < n + 1; i++)
        dis[i] = 1e18;

    dijkstra(adj, src, dis);

    int t;
    cin >> t;

    while (t--)
    {
        int d, w;
        cin >> d >> w;
        bool canReallyGo = dis[d] <= w;
        cout << (canReallyGo ? "YES" : "NO") << endl;
    }

    return 0;
}