#include <bits/stdc++.h>
using namespace std;

bool recursiveHelper(string target, vector<string> wordBank, string temp, int n)
{
    if (n < 0)
        return false;

    if (temp == target)
        return true;

    for (string word : wordBank)
    {
        bool op1 = recursiveHelper(target, wordBank, temp + word, n - 1);
        bool op2 = recursiveHelper(target, wordBank, word + temp, n - 1);
        bool op3 = recursiveHelper(target, wordBank, temp, n - 1);

        cout << temp << endl;
        return op1 || op2 || op3;
    }
}

bool canConstruct(string target, vector<string> wordBank)
{
    int n = wordBank.size() - 1;
    return recursiveHelper(target, wordBank, string(), n);
}

int main()
{
    string target;
    cin >> target;

    vector<string> wordBank;
    string word;
    while (cin >> word)
    {
        wordBank.push_back(word);
    }

    bool result = canConstruct(target, wordBank);
    cout << (result ? "true" : "false");

    return 0;
}