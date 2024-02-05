#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    // Input
    int v, e;
    cin >> v >> e;
    vector<Edge> edges;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }

    // Calculation
    int dis[v + 1];
    for (int i = 1; i <= v; i++)
        dis[i] = 30000;

    dis[1] = 0;

    for (int i = 1; i <= v; i++)
    {
        for (Edge ed : edges)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] < 30000 && dis[u] + c < dis[v])
                dis[v] = dis[u] + c;
        }
    }

    // Output
    for (int i = 1; i <= v; i++)
        cout << dis[i] << " ";

    return 0;
}