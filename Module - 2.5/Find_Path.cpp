#include <bits/stdc++.h>
using namespace std;

/*
    Question: You will be given an undirected graph as input. Then you will be given a query Q. For each query, you will be given source S and destination D. You need to print the shortest distance between S and D. If there is no path from S to D, print -1.
*/

int shortestDistance(vector<int> graph[], int v, int src, int des)
{

    int vis[v];
    int par[v];
    memset(vis, -1, sizeof(vis));
    memset(par, -1, sizeof(par));

    // 1st Part
    queue<int> qu;
    qu.push(src);
    vis[src] = 1;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int child = graph[u][i];
            if (vis[child] == -1)
            {
                vis[child] = 1;
                par[child] = u;
                qu.push(child);
            }
        }
    }

    // 2nd Part
    int dis = -1;

    int path = des;
    bool isFound = false;
    while (path != -1)
    {
        dis++;
        if (path == src)
            isFound = true;
        path = par[path];
    }

    if (!isFound)
        dis = -1;

    return dis;
}

int main()
{

    int v, e;
    cin >> v >> e;
    vector<int> graph[v+1];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // For Undirected graph
    }

    vector<int> result;
    int t;
    cin >> t;

    while (t--)
    {
        int src, des;
        cin >> src >> des;
        int dis = shortestDistance(graph, v, src, des);
        result.push_back(dis);
    }

    for (int it : result)
        cout << it << endl;

    return 0;
}