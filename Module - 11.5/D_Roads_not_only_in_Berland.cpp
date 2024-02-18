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
            par[par1] = par2;
            g_size[par2] += g_size[par1];
        }
    }
};

int main()
{
    int n;
    cin >> n;
    DSU cities = DSU(n + 1);

    vector<pair<int, int>> closeRoads;

    int i = n - 1;
    while (i--)
    {
        int u, v;
        cin >> u >> v;

        int par1 = cities.find(u);
        int par2 = cities.find(v);

        // Find roads that need to be closed
        if (par1 == par2)
            closeRoads.push_back({u, v});

        cities.unionBySize(u, v);
    }

    // Find  roads that need to be connected

    // 1st way to find roads that need to be connected
    // set<int> openRoads;
    // for (int i = 1; i <= n; i++)
    //     openRoads.insert(cities.find(i));

    // 2nd way to find roads that need to be connected
    vector<int> openRoads = {1};
    for (int i = 2; i <= n; i++)
    {
        if (cities.find(1) != cities.find(i))
            openRoads.push_back(i), cities.unionBySize(1, i);
    }

    int roadsRequired = closeRoads.size();
    cout << roadsRequired << endl;

    while (roadsRequired--)
    {
        pair<int, int> road = closeRoads.back();
        closeRoads.pop_back();
        cout << road.first << " " << road.second << " ";

        cout << openRoads.back() << " ";
        openRoads.pop_back();
        cout << openRoads.back() << endl;
    }

    return 0;
}