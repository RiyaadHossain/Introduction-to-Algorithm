#include <bits/stdc++.h>
using namespace std;

string string1, string2;

/* Top Down Approach */
int memo[1001][1001];
int lcs(int s1, int s2)
{
    if (s1 == 0 || s2 == 0)
        return 0;

    if (memo[s1][s2] != -1)
        return memo[s1][s2];

    if (string1[s1 - 1] == string2[s2 - 1])
        return memo[s1][s2] = lcs(s1 - 1, s2 - 1) + 1;

    int op1 = lcs(s1 - 1, s2);
    int op2 = lcs(s1, s2 - 1);
    return memo[s1][s2] = max(op1, op2);
}

int lcs_recursive()
{
    memset(memo, -1, sizeof(memo));
    int s1 = string1.size(), s2 = string2.size();

    return lcs(s1, s2);
}

/* Bottom Up Approach */
string lcs_iterative()
{

    int s1 = string1.size(), s2 = string2.size();
    int dp[s1 + 1][s2 + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (string1[i - 1] == string2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string result;
    int i = s1, j = s2;
    while (i != 0 && j != 0)
    {

        if (string1[i - 1] == string2[j - 1])
            result.push_back(string1[i - 1]), i--, j--;
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{

    cin >> string1 >> string2;

    // int result = lcs_recursive();
    // cout << result << endl;

    string result = lcs_iterative();
    cout << result.size() << endl;
    cout << result;

    return 0;
}