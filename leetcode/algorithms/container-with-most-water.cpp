#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = -1, l = 0, r = height.size() - 1;
        while (l < r)
        {
            maxArea = max(maxArea, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return maxArea;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(height) << endl;
}