#include <bits/stdc++.h>
using namespace std;
using IntArray = vector<int>;

vector<int> graph[1005];
int visited[1005];
int parent[1005];

void makeGraph(int v, int e)
{

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Undirected
    }
}

void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = 1;

    while (!qu.empty())
    {
        int par = qu.front();
        qu.pop();

        for (int i = 0; i < graph[par].size(); i++)
        {
            int child = graph[par][i];
            if (visited[child] == -1)
            {
                visited[child] = 1;
                parent[child] = par;
                qu.push(child);
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    makeGraph(v, e);

    memset(visited, -1, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    int src;
    cin >> src;
    bfs(src);

    int des;
    cin >> des;

    vector<int> srcToDes;
    int road = des;
    while (road != -1)
    {
        srcToDes.push_back(road);
        road = parent[road];
    }

    reverse(srcToDes.begin(), srcToDes.end());

    for (int it : srcToDes)
        cout << it << " ";

    return 0;
}