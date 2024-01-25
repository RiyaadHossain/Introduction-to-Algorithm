#include <bits/stdc++.h>
using namespace std;

/*
    Question: You will be given an undirected graph which will be connected as input. Then you will be given a level L. You need to print the node values at level L in descending order. The source will be 0 always.
*/

vector<int> printLevelVertices(vector<int> graph[], int v, int src, int targetLevel)
{
    int vis[v] = {0};
    queue<pair<int, int>> qu;
    qu.push({src, 0});
    vis[src] = 1;

    vector<int> result;

    while (!qu.empty())
    {
        pair<int, int> u = qu.front();
        qu.pop();

        int vertex = u.first;
        int level = u.second;

        if (level == targetLevel)
            result.push_back(vertex);

        for (int i = 0; i < graph[vertex].size(); i++)
        {
            int child = graph[vertex][i];
            if (vis[child] == 0)
            {
                vis[child] = 1;
                qu.push({child, level + 1});
            }
        }
    }

    return result;
}

int main()
{

    int v, e;
    cin >> v >> e;
    vector<int> graph[v];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // For Undirected graph
    }

    int target;
    cin >> target;
    vector<int> result = printLevelVertices(graph, v, 0, target);

    reverse(result.begin(), result.end());

    for (int it : result)
        cout << it << " ";

    return 0;
}