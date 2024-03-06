#include <bits/stdc++.h>
using namespace std;

string string1, string2;

/* Recursive Approach */
string lcsString, mx_lcsString;
void helper(int s1, int s2)
{
    if (s1 == 0 || s2 == 0)
        return;

    if (string1[s1 - 1] == string2[s2 - 1])
    {
        lcsString.push_back(string1[s1 - 1]);
        if (lcsString.size() > mx_lcsString.size())
            mx_lcsString = lcsString;

        helper(s1 - 1, s2 - 1);
        return;
    }

    lcsString.clear();
    helper(s1, s2 - 1);
    helper(s1 - 1, s2);
}

int solve(int i, int j, int count)
{

    if (i == 0 || j == 0)
    {
        return count;
    }

    if (string1[i - 1] == string2[j - 1])
        return solve(i - 1, j - 1, count + 1);

    int count1 = solve(i, j - 1, 0);
    int count2 = solve(i - 1, j, 0);

    count = max({count, count1, count2});
    return count;
}

int lcsubstr()
{
    int s1 = string1.size(), s2 = string2.size();
    int ans = solve(s1, s2, 0);
    return ans;
}

string lc_substring_recursion()
{
    int s1 = string1.size(), s2 = string2.size();
    helper(s1, s2);
    reverse(mx_lcsString.begin(), mx_lcsString.end());

    return mx_lcsString;
}

/* Tabulative Approach */
string lc_substring_tabulation()
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
                dp[i][j] = 0;
        }
    }

    // Find where longest common substring ends
    int pi, pj, mx = 0;
    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (dp[i][j] > mx)
                mx = dp[i][j], pi = i, pj = j;
        }
    }

    string result;
    while (dp[pi][pj] != 0)
    {
        result.push_back(string1[pi - 1]);
        pi--, pj--;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    cin >> string1 >> string2;

    cout << lcsubstr() << endl;

    // string result = lc_substring_recursion();
    // cout << result.size() << endl;
    // cout << result;

    // string result = lc_substring_tabulation();
    // cout << result.size() << endl;
    // cout << result;

    return 0;
}