#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        vector<int> prefix_prod(nums.size()), suffix_prod(nums.size());
        int n = nums.size();
        prefix_prod[0] = 1;
        suffix_prod[n - 1] = 1;
        for (int i = 1; i < n; ++i)
        {
            prefix_prod[i] = prefix_prod[i - 1] * nums[i - 1];
            suffix_prod[n - i - 1] = suffix_prod[n - i] * nums[n - i];
        }

        for (int i = 0; i < n; ++i)
        {
            ans.push_back(prefix_prod[i] * suffix_prod[i]);
        }
        return ans;
    }
};

class Solution1
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefix_prod = 1, suffix_prod = 1;

        for (int i = 0; i < n; ++i)
        {
            ans[i] *= prefix_prod;
            prefix_prod *= nums[i];
            ans[n - i - 1] *= suffix_prod;
            suffix_prod *= nums[n - i - 1];
        }
        return ans;
    }
};

int main()
{
    // vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> nums = {1, 2, 3, 4};

    Solution1 s;
    vector<int> ans = s.productExceptSelf(nums);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}