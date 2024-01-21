#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*
        Data Structure: vector of array
        Best at: how many connections a node has. -> have iterate through vector values of a node
     */

    int n, e;
    cin >> n, e;

    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a); // Not require for directed graph
    }

    return 0;
}