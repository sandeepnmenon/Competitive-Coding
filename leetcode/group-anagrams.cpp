#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countingSort(string s)
    {
        int count[26] = {0};
        for (char c : s)
        {
            count[c - 'a']++;
        }
        string sorted_string;
        for (int i = 0; i < 26; ++i)
        {
            sorted_string += string(count[i], i + 'a');
        }

        return sorted_string;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); ++i)
        {
            string basic_string = strs[i];
            basic_string = countingSort(basic_string);
            // sort(basic_string.begin(), basic_string.end());
            if (map.find(basic_string) == map.end())
            {
                map[basic_string] = vector<string>{strs[i]};
            }
            else
            {
                map[basic_string].push_back(strs[i]);
            }
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = map.begin(); it != map.end(); ++it)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // vector<string> strs = {""};
    // vector<string> strs = {"a"};

    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}