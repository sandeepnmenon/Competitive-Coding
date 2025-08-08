#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto v : intervals)
        {
            if (ans.empty())
                ans.push_back(v);
            else
            {
                if (ans.back()[1] >= v[0])
                    ans.back()[1] = max(ans.back()[1], v[1]);
                else
                    ans.push_back(v);
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    vector<vector<int>> ans = s.merge(intervals);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}