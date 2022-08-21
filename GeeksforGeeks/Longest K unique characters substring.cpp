//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        unordered_map<char, int> shash;
        int start = 0, n = s.length();
        int ans = -1, cur_longest = 0;
        for (int end = 0; end < n; ++end)
        {
            shash[s[end]]++;
            while (start <= end and shash.size() > k)
            {
                shash[s[start]]--;
                if (shash[s[start]] == 0)
                    shash.erase(s[start]);
                start++;
                if (shash.size() == k)
                {
                    ans = max(ans, end - start + 1);
                }
            }
            if (shash.size() == k)
            {
                ans = max(ans, end - start + 1);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    string s = "aabacbebebe";
    int k = 3;
    Solution ob;
    cout << ob.longestKSubstr(s, k) << endl;

    return 0;
}

// } Driver Code Ends