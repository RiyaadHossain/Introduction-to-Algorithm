#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, ll>;

const int N = 2001;
ll cost[N];
int par[N];

void initAuxArr(int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = -1, cost[i] = LLONG_MAX; // Init cost as biggest value
}

class CMP
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};

void printShortestPath(vector<pi> adj[], int src, int des, int n)
{
    initAuxArr(n);

    priority_queue<pi, vector<pi>, CMP> qu;
    qu.push({src, 0});
    cost[src] = 0;

    while (!qu.empty())
    {
        pi front = qu.top();
        qu.pop();

        int u = front.first;
        ll w = front.second;

        for (pi ch : adj[u])
        {
            int v = ch.first;
            ll totalCost = w + ch.second; // Total cost calculation
            if (totalCost < cost[v])
                qu.push({v, totalCost}), cost[v] = totalCost, par[v] = u;
        }
    }

    if (par[des] == -1)
    {
        cout << -1;
        return;
    }

    cout << cost[des] << endl;
    
    vector<int> path;
    while (des != -1)
        path.push_back(des), des = par[des];

    reverse(path.begin(), path.end());
    for (int p : path)
        cout << p << " ";
}

int main()
{
    int n, e;
    cin >> n >> e;

    int src, des;
    cin >> src >> des;

    vector<pi> adj[n + 1];
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    printShortestPath(adj, src, des, n);

    return 0;
}