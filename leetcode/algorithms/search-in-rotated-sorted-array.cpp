#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pos = binary_search(nums, 0, nums.size() - 1, target);

        return pos;
    }

    int binary_search(vector<int> &nums, int l, int r, int target)
    {
        if (l < 0 or r >= nums.size() or l > r)
            return -1;

        if (l == r)
        {
            return (nums[l] == target) ? l : -1;
        }

        int mid = (l + r) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[l] <= nums[mid])
        {
            if (target <= nums[mid] and target >= nums[l])
                return binary_search(nums, l, mid - 1, target);
            else
                return binary_search(nums, mid + 1, r, target);
        }
        else
        {
            if (target >= nums[mid] and target <= nums[r])
                return binary_search(nums, mid + 1, r, target);
            else
                return binary_search(nums, l, mid - 1, target);
        }
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution sol;
    cout << sol.search(nums, target) << endl;
}