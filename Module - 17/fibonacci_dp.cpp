#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int dp[N];

void initDP()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
}

// Recursive Call without DP -> O(2^n)
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive Call with DP -> O(n)
int fibonacciDP(int n)
{
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonacciDP(n - 1) + fibonacciDP(n - 2); // Memoization
}

int main()
{
    int n;
    cin >> n;
    initDP();

    cout << fibonacciDP(n);

    return 0;
}