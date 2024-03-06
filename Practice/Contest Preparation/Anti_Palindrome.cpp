#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> freq;
bool semiPilandrome(string str)
{
    freq.resize(26, 0);

    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    int oddFound = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] % 2)
            oddFound++;

    if (n % 2)
        return oddFound == 1;

    return oddFound == 0;
}

int minOperation(string str)
{
    if (!semiPilandrome(str))
        return 0;

    if (n % 2 == 0)
        return 1;

    bool allSame = true;
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0 && freq[i] != n)
            allSame = false;

    if (allSame)
        return 2;

    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string str;
        cin >> str;

        int result = minOperation(str);
        cout << result << '\n';

        freq.clear();
    }

    return 0;
}