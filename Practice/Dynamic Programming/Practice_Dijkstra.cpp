#include <bits/stdc++.h>
using namespace std;
using PairInt = pair<int, int>;

class CMP
{
public:
    bool operator()(PairInt a, PairInt b)
    {
        return a.second > b.second;
    }
};

void initCost(int cost[], int n)
{
    for (int i = 0; i < n; i++)
        cost[i] = INT_MAX;
}

int dijkstra(vector<PairInt> graph[], int n, int src, int des)
{
    int cost[n];
    initCost(cost, n);

    priority_queue<PairInt, vector<PairInt>, CMP> pq;
    pq.push({src, 0});
    cost[src] = 0;

    while (!pq.empty())
    {
        PairInt front = pq.top();
        pq.pop();

        int u = front.first;
        int c = front.second;

        for (PairInt child : graph[u])
        {
            int v = child.first, vc = child.second;
            int totalCost = c + vc;
            if (totalCost < cost[v])                          // Crucial condition
                cost[v] = totalCost, pq.push({v, totalCost}); // Update new cost
        }
    }

    return cost[des] != INT_MAX ? cost[des] : -1;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<PairInt> graph[n];

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    int src, des;
    cin >> src >> des;

    int result = dijkstra(graph, n, src, des);
    cout << result;

    return 0;
}