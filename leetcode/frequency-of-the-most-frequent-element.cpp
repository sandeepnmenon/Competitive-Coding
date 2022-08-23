#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1)
            return 1;
        sort(nums.begin(), nums.end());

        long long maxFreq = 1;
        long long preSum = 0;
        int l = 0, r = 1;
        long long windowSize = r - l + 1;

        while (r < n)
        {
            preSum = preSum + nums[r - 1];
            windowSize = r - l + 1;
            while (l < r and (windowSize - 1) * nums[r] - preSum > k)
            {
                preSum -= nums[l];
                l++;
                windowSize = r - l + 1;
                maxFreq = max(maxFreq, windowSize);
            }
            r++;
        }

        return max(maxFreq, windowSize);
    }
};

int main()
{
    vector<int> nums = {3, 5};
    int k = 3;
    Solution sol;
    cout << sol.maxFrequency(nums, k) << endl;
}