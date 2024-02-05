#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int par[N];
int g_size[N];
int level[N];

void init_dsu(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        g_size[i] = 1;
        level[i] = 0;
    }
}

int find_parent(int node)
{
    if (par[node] == -1)
        return node;

    int parent = find_parent(par[node]);
    par[node] = parent;
    return parent;
}

void union_node(int node1, int node2)
{
    int parent1 = find_parent(node1);
    int parent2 = find_parent(node2);

    par[parent1] = parent2;
}

void union_by_size(int node1, int node2)
{
    int parent1 = find_parent(node1);
    int parent2 = find_parent(node2);

    if (g_size[parent1] >= g_size[parent2])
    {
        par[parent2] = parent1;
        g_size[parent1] += g_size[parent2];
    }
    else
    {
        par[parent1] = parent2;
        g_size[parent2] += g_size[parent1];
    }
}

void union_by_rank(int node1, int node2)
{
    int parent1 = find_parent(node1);
    int parent2 = find_parent(node2);

    if (level[parent1] > level[parent2])
        par[parent2] = parent1;
    else if (level[parent2] > level[parent1])
        par[parent1] = parent2;
    else
        par[parent2] = parent1, level[parent1]++;
}

int main()
{
    int n, c;
    cin >> n >> c;

    init_dsu(n);

    while (c--)
    {
        int node1, node2;
        cin >> node1 >> node2;

        union_by_rank(node1, node2);
    }
    cout << level[0] << endl;
    cout << "parent of 2: " << find_parent(4) << endl;

    return 0;
}