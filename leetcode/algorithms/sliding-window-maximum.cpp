#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> max_elements;
        int l = 0, r = 0;
        int n = nums.size();
        vector<int> ans;
        while (r < n)
        {
            if (max_elements.size() == 0)
            {
                max_elements.push_back(r);
            }
            else
            {
                if (nums[r] <= nums[max_elements.back()])
                {
                    max_elements.push_back(r);
                }
                else
                {
                    while (max_elements.size() > 0 and nums[r] > nums[max_elements.back()])
                        max_elements.pop_back();
                    max_elements.push_back(r);
                }
            }
            if (l > max_elements.front())
                max_elements.pop_front();
            r++;
            if (r >= k)
            {
                ans.push_back(nums[max_elements.front()]);
                l++;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution s;
    vector<int> ans = s.maxSlidingWindow(nums, k);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}