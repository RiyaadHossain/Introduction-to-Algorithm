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

    vector<Edge> edge;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edge.push_back(Edge(u, v, c));
    }

    // Get Distance
    int dis[v];
    for (int i = 0; i < v; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;
    for (int i = 0; i < v; i++)
    {
        for (Edge ed : edge)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
                dis[v] = dis[u] + c;
        }
    }

    // Output
    bool cycleDetected = false;
    for (Edge ed : edge)
    {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if (dis[u] + c < dis[v])
        {
            cycleDetected = true;
            break;
        }
    }

    cout << (cycleDetected ? "Cycle Detected" : "Cycle not Detected");

    return 0;
}