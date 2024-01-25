#include <bits/stdc++.h>
using namespace std;

/*
    Question: You will be given an undirected graph as input. Then you will be given a node N. You need to print the number of nodes that are directly connected to the node N.
*/

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

    int n;
    cin >> n;

    vector<int> node = graph[n];
    cout << node.size() << " ";

    return 0;
}