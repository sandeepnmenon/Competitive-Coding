#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];
        return findMin_search(nums, 0, nums.size() - 1, nums.size());
    }

    int findMin_search(vector<int> nums, int l, int r, int n)
    {

        int mid = l + (r - l) / 2;
        // cout << l << " " << r << " " << mid << endl;

        if (l >= r)
            return min(nums[l], nums[r]);

        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];

        if (nums[mid - 1] > nums[mid])
            return nums[mid];

        if (nums[0] < nums[mid])
        {
            return min(nums[l], findMin_search(nums, mid + 1, r, n));
        }
        else
        {
            return min(nums[mid], findMin_search(nums, l, mid - 1, n));
        }
    }
};

int main()
{
    // vector<int> nums = {5, 1, 2, 3, 4};
    // vector<int> nums = {5, 1};
    vector<int> nums = {11, 13, 15, 17};

    Solution sol;
    cout << sol.findMin(nums) << endl;
}