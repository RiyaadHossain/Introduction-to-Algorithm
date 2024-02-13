#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

class DSU
{
    vector<int> par;
    vector<int> sz;

public:
    DSU(int n)
    {
        par.resize(n, -1);
        sz.resize(n, 1);
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

        if (sz[par1] >= sz[par2])
            par[par2] = par1, sz[par1] += sz[par2];
        else
            par[par1] = par2, sz[par2] += sz[par1];
    }
};

int main()
{
    int n;
    cin >> n;

    DSU cities = DSU(n + 1);
    vector<pi> closeRoads;

    int j = n - 1;
    while (j--)
    {
        int u, v;
        cin >> u >> v;

        if (cities.find(u) == cities.find(v))
            closeRoads.push_back({u, v});

        cities.unionBySize(u, v);
    }

    vector<pi> openRoads;
    int mainPar = cities.find(1);

    for (int i = 2; i <= n; i++)
    {
        mainPar = cities.find(1);
        int currPar = cities.find(i);
        if (currPar != mainPar)
            openRoads.push_back({1, currPar}), cities.unionBySize(currPar, mainPar);
    }

    cout << openRoads.size() << endl;

    n = closeRoads.size();
    for (int i = 0; i < n; i++)
    {
        cout << closeRoads[i].first << " " << closeRoads[i].second << " "
             << openRoads[i].first << " " << openRoads[i].second << endl;
    }

    return 0;
}