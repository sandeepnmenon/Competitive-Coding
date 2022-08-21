#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkHash(unordered_map<char, int> shash, unordered_map<char, int> thash)
    {
        for (auto p : thash)
        {
            if (p.second > shash[p.first])
                return false;
        }

        return true;
    }

    pair<int, int> min_window(pair<int, int> sub_pos, pair<int, int> window)
    {

        if (window.second - window.first < sub_pos.second - sub_pos.first)
            sub_pos = window;

        return sub_pos;
    }
    string minWindow(string s, string t)
    {
        int l = 0, r = 0, s_len = s.length(), t_len = t.length();
        unordered_map<char, int> whash, thash;
        for (char c : t)
            thash[c]++;

        pair<int, int> sub_pos = make_pair(0, s_len);
        int required_matches = thash.size();
        int matches = 0;
        int cnt = 0;
        while (r < s_len or l < s_len)
        {
            cnt++;
            if (r < s_len)
                whash[s[r]]++;

            if (thash.count(s[r]) and thash[s[r]] == whash[s[r]])
                matches++;
            while (l <= r and matches == required_matches)
            {
                sub_pos = min_window(sub_pos, make_pair(l, r));
                whash[s[l]]--;
                if (thash.count(s[l]) and whash[s[l]] < thash[s[l]])
                    matches--;
                l++;

                if (sub_pos.second - sub_pos.first + 1 == t_len)
                    break;
            }

            if (r == s_len)
            {
                if (!checkHash(whash, thash))
                    break;

                whash[s[l]]--;
                l++;
            }
            else if (r < s_len)
            {
                r++;
            }
        }
        cout << cnt << endl;                     // Number of iterations
        cout << s.length() + t.length() << endl; //|s| + |t|

        if (sub_pos == make_pair(0, s_len))
            return "";
        else
            return s.substr(sub_pos.first, sub_pos.second - sub_pos.first + 1);
    }
};

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    // ifstream read_file("./testcases/minimum-window-substring_1.txt");
    // getline(read_file, s, '\n');
    // getline(read_file, t, '\n');
    Solution sol;
    cout << sol.minWindow(s, t) << endl;
}