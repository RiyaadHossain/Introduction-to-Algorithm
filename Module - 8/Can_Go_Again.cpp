#include <bits/stdc++.h>
#define ll long long
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

void bellmanFord(vector<Edge> &edges, ll dis[], int src, bool &cycleDetected)
{
    dis[src] = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        for (Edge ed : edges)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] < LONG_LONG_MAX && c + dis[u] < dis[v])
                dis[v] = c + dis[u];
        }
    }

    for (Edge ed : edges)
    {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if (dis[u] < LONG_LONG_MAX && c + dis[u] < dis[v])
            cycleDetected = true;
    }

}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }

    int src;
    cin >> src;

    ll dis[n + 1];
    for (int i = 0; i < n + 1; i++)
        dis[i] = LONG_LONG_MAX;

    bool cycleDetected = false;
    bellmanFord(edges, dis, src, cycleDetected);

    int t;
    cin >> t;

    while (t--)
    {
        if (cycleDetected)
        {
            cout << "Negative Cycle Detected";
            break;
        }

        int d;
        cin >> d;

        if (dis[d] < LONG_LONG_MAX)
            cout << dis[d] << endl;
        else
            cout << "Not Possible" << endl;
    }

    return 0;
}