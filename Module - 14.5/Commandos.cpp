#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int src, int vis[], int n)
{
    memset(vis, -1, n * sizeof(int));

    queue<int> qu;
    qu.push(src);
    vis[src] = 0;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (int v : adj[u])
        {
            if (vis[v] == -1)
                qu.push(v), vis[v] = vis[u] + 1;
        }
    }
}

int main()
{
    int t, i = 0;
    cin >> t;

    while (i < t)
    {
        int n, e;
        cin >> n >> e;

        vector<int> adj[n];
        while (e--)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src, des;
        cin >> src >> des;

        int visit_from_src[n];
        int visit_from_des[n];

        bfs(adj, src, visit_from_src, n);
        bfs(adj, des, visit_from_des, n);


        int ans = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, visit_from_src[j] + visit_from_des[j]);
        }

        string _case = "Case " + to_string(i + 1) + ": ";
        cout << _case << ans << endl;

        i++;
    }

    return 0;
}