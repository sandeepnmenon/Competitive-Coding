#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int dp[100] = {0};
        dp[0] = 1;
        int n = s.length();

        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == '0' and (s[i - 1] != '1' and s[i - 1] != '2'))
            {
                dp[n - 1] = 0;
                break;
            }

            if (s[i] == '0')
            {
                dp[i] = i == 1 ? 1 : dp[i - 2];
            }
            else if ((s[i] <= '6' and s[i - 1] == '2') or (s[i - 1] == '1'))
            {
                dp[i] = i == 1 ? dp[i - 1] + 1 : dp[i - 1] + dp[i - 2];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    string str = "210111";
    Solution s;
    cout << s.numDecodings(str) << endl;
}