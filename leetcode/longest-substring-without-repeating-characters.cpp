#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if (n < 2)
            return n;
        int ans = 1, longest = 1;
        int start = 1, first_idx = 0;
        while (start < n)
        {
            string sub = s.substr(first_idx, start - first_idx);
            // cout << sub << endl;
            if (sub.find(s[start]) != string::npos)
            {
                first_idx = first_idx + sub.find(s[start]) + 1;
                longest = start - first_idx + 1;
            }
            else
            {
                // cout << " - " << s[start] << endl;
                longest++;
            }
            start++;
            ans = max(ans, longest);
        }

        return ans;
    }
};

int main()
{
    string str = "abcabcbb";
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
}