#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canReach(ll target, ll val)
{
    if (target == val)
        return 1;

    if (target < val)
        return 0;

    ll multi10 = val * 10, multi20 = val * 20;
    return (canReach(target, multi10) || canReach(target, multi20));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll num;
        cin >> num;

        bool result = canReach(num, 1);
        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}