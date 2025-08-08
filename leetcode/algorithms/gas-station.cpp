#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(), sum = 0;
        if (n == 1)
        {
            if (gas[0] >= cost[0])
                return 0;
            else
                return -1;
        }

        int i = n - 1, j = 0;
        sum = gas[i] - cost[i];
        while (j < i)
        {
            if (sum >= 0)
            {
                sum += gas[j] - cost[j];
                j++;
            }
            else
            {
                i--;
                sum += gas[i] - cost[i];
            }
        }

        return sum >= 0 ? i : -1;
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
}