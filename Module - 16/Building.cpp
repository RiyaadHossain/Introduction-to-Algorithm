#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, ll>;

class DSU
{
    vector<int> par;
    vector<int> g_size;

public:
    DSU(int n)
    {
        par.resize(n, -1);
        g_size.resize(n, 1);
    }

    int find(int node)
    {
        if (par[node] == -1)
            return node;

        int parent = find(par[node]);
        par[node] = parent;
        return parent;
    }

    void unionBySize(int node1, int node2)
    {
        int par1 = find(node1);
        int par2 = find(node2);

        if (par1 == par2)
            return;

        if (g_size[par1] <= g_size[par2])
        {
            par[par2] = par1;
            g_size[par1] += g_size[par2];
        }
        else
        {
            par[par2] = par1;
            g_size[par1] += g_size[par2];
        }
    }
};

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

    sort(edges.begin(), edges.end());

    ll totalCost = 0;
    DSU dsu = DSU(n + 1);
    for (pair<int, pi> ed : edges)
    {
        int w = ed.first;
        int u = ed.second.first, v = ed.second.second;

        int par1 = dsu.find(u);
        int par2 = dsu.find(v);

        if (par1 != par2)
            totalCost += w;

        dsu.unionBySize(par1, par2);
    }

    bool isPossible = true;
    int parent = dsu.find(1);
    for (int i = 2; i <= n; i++)
    {
        if (dsu.find(i) != parent)
            isPossible = false;
    }

    cout << (isPossible ? totalCost : -1);

    return 0;
}