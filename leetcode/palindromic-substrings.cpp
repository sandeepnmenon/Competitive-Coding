#include <bits/stdc++.h>
using namespace std;

class Solution
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

int main()
{
    string s = "madam";
    Solution sol;
    cout << sol.countSubstrings(s) << endl;
}
