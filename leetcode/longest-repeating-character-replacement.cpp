#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> hash(26, 0);
        int l = 0, r = 0, n = s.size();
        int ans = 1, maxFreqSubstr = 1;
        // length of substring such that k > windowSize - maxFrequency
        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxFreqSubstr = max(maxFreqSubstr, hash[s[r] - 'A']);
            if ((r - l + 1) - maxFreqSubstr > k)
            {
                hash[s[l] - 'A']--;
                l++;
                maxFreqSubstr = *max_element(hash.begin(), hash.end());
            }
            r++;
        }

        return r - l;
    }
};

int main()
{
    string str = "ABAB";
    int k = 1;
    Solution s;
    cout << s.characterReplacement(str, k) << endl;
}