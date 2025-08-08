#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count[3] = {0};
        for (int x : nums)
        {
            count[x]++;
        }
        int cur_cnt = 0, i = 0;
        while (i < nums.size())
        {
            if (count[cur_cnt] > 0)
            {
                nums[i] = cur_cnt;
                count[cur_cnt]--;
            }
            else
            {
                cur_cnt++;
                continue;
            }
            i++;
        }
    }
};

class Solution2
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1, current = 0;
        while (current <= high)
        {
            switch (nums[current])
            {
            case 0:
                swap(nums[low], nums[current]);
                low++;
                current++;
                break;
            case 1:
                current++;
                break;
            case 2:
                swap(nums[current], nums[high]);
                high--;
                break;
            default:
                break;
            }
        }
    }
};

int main()
{
    Solution2 sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
}