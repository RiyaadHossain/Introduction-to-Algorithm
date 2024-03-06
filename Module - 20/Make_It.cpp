#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
bool recursion(int target, int currVal)
{
    if (target == currVal)
        return 1;

    if (target < currVal)
        return 0;

    if (dp[currVal] != -1)
        return dp[currVal];

    int add3 = recursion(target, currVal + 3);
    int multiply2 = recursion(target, currVal * 2);

    return dp[currVal] = add3 || multiply2;
}

bool makeIt(int val)
{
    dp.clear();
    dp.resize(val + 1, -1);
    return recursion(val, 1);
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int val;
        cin >> val;

        bool result = makeIt(val);
        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}