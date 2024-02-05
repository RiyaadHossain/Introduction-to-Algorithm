#include <bits/stdc++.h>
using namespace std;

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
    }

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        bool isPossible = false;
        for (int ch : graph[a])
            if (ch == b)
                isPossible = true;

        if (a == b)
            isPossible = true;

        cout << (isPossible ? "YES" : "NO") << endl;
    }

    return 0;
}