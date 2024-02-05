#include <bits/stdc++.h>
using namespace std;

/*
    Question: You will be given a directed graph as input. Then you will be given a node N. You need to tell the number of nodes that can be visited from node N.
*/
const int n = 10e2;
int vis[n];

int dfs(vector<vector<int>> &graph, int src) {
    vis[src] = 1;

    int connecetedNodes = 1;
    for(int ch:graph[src]) {
        if(vis[ch] == 0)
            connecetedNodes += dfs(graph, ch);
    }

    return connecetedNodes;
}

int visitedNode(vector<vector<int>> &graph, int src){
    memset(vis, 0, sizeof(vis));

    return dfs(graph, src);
};

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // For Undirected graph
    }

    int src;
    cin >> src;

    int result = visitedNode(graph, src);
    cout << result;

    return 0;
}