#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Hash function
    struct hashFunction
    {
        size_t operator()(const tuple<int,
                                      int, int> &x) const
        {
            return get<0>(x) ^ get<1>(x) ^ get<2>(x);
        }
    };
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        unordered_set<tuple<int, int, int>, hashFunction> result_set;
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    result_set.insert(make_tuple(nums[i], nums[l], nums[r]));
                    l++;
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        for (auto it = result_set.begin(); it != result_set.end(); ++it)
        {
            result.push_back(vector<int>{get<0>(*it), get<1>(*it), get<2>(*it)});
        }

        return result;
    }
};

int main()
{
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0, 0, 0, 0};

    Solution s;
    vector<vector<int>> ans = s.threeSum(nums);
    for (vector<int> row : ans)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
}