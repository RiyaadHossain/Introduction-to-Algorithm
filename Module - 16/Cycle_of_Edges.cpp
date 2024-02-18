#include <bits/stdc++.h>
using namespace std;

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

    int cycleCnt = 0;
    DSU dsu = DSU(n + 1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;

        int par1 = dsu.find(u);
        int par2 = dsu.find(v);

        if (par1 == par2)
            cycleCnt++;

        dsu.unionBySize(par1, par2);
    }

    cout << cycleCnt;

    return 0;
}