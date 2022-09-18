#include <bits/stdc++.h>
using namespace std;

class SolutionNeetCode
{
public:
    int countSubstrings(string s)
    {
        int len = s.length();
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
            ans += countPalindromes(s, i, i);
            ans += countPalindromes(s, i, i + 1);
        }

        return ans;
    }

    int countPalindromes(string s, int l, int r)
    {
        int ans = 0;
        int len = s.length();
        while (l >= 0 and r < len and s[l] == s[r])
        {
            ans += 1;
            l--;
            r++;
        }
        return ans;
    }
};

class Solution
{
public:
    int countSubstrings(string s)
    {
        int len = s.length();
        int ans = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = len - 1; i >= 0; --i)
        {
            for (int j = i; j < len; ++j)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (j == i + 1)
                {
                    dp[i][j] = (s[j] == s[i] ? 1 : 0);
                }
                else
                {
                    dp[i][j] = (s[j] == s[i] ? dp[i + 1][j - 1] : 0);
                }
                ans += dp[i][j];
            }
        }

        return ans;
    }
};

int main()
{
    string s = "madam";
    Solution sol;
    cout << sol.countSubstrings(s) << endl;
}
