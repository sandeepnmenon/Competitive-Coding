#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> n_map;
        for (int num : nums)
        {
            n_map[num] = true;
        }
        int ans = 0, cur_ans = 1;
        for (int num : nums)
        {
            if (n_map.find(num - 1) == n_map.end())
            {
                cur_ans = 1;
                int cur_num = num;
                while (n_map.find(cur_num + 1) != n_map.end())
                {
                    cur_num++;
                    cur_ans++;
                }
            }
            ans = max(ans, cur_ans);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    // vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> nums = {1, 2, 3, 4, 5, 7, 8, 9, 10};

    cout << s.longestConsecutive(nums) << endl;
    return 1;
}