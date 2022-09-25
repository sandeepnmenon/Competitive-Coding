#include <bits/stdc++.h>
using namespace std;

// Find maximum number of books that can be bought using the budget given the bundleCosts
int getMaximumPossibleNumber(int budget, vector<int> bundleCosts, vector<int> bundleNumber)
{
    int n = bundleCosts.size();
    vector<int> dp(budget + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = bundleCosts[i]; j <= budget; j++)
        {
            dp[j] = max(dp[j], dp[j - bundleCosts[i]] + bundleNumber[i]);
        }
    }
    return dp[budget];
}

int main()
{
    int budget = 50;
    vector<int> bundleCosts = vector<int>{49, 25, 25};
    vector<int> bundleNumber = vector<int>{100, 51, 51};
    cout << getMaximumPossibleNumber(budget, bundleCosts, bundleNumber) << endl;
}