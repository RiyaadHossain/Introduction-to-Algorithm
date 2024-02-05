#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v+5, vector<int>(0));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // For Undirected graph
    }

    int t;
    cin >> t;

    while (t--)
    {
        int v;
        cin >> v;

        if (graph[v].size() == 0)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> result = graph[v];

        sort(result.begin(), result.end(), greater<int>());

        for (int it : result)
            cout << it << " ";

        cout << endl;
    }

    return 0;
}