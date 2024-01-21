#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*
        Data Structure: matrix
        Best at: is there any connection between two nodes.
        Worst at: how many connections a node has. -> have iterate through all the row values (better - adjacency list)
     */

    int nodes, edges;
    cin >> nodes >> edges;

    int mat[nodes][nodes];
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1;
        mat[b][a] = 1; // Not require for directed graph
    }

    return 0;
}