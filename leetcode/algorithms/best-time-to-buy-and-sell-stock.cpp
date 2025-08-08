#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int prev_low = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prev_low)
            {
                max_profit = max(max_profit, prices[i] - prev_low);
            }
            else
            {
                prev_low = prices[i];
            }
        }

        return max_profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}