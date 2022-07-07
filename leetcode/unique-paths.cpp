#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int grid[100][100] = {[0 ... 99][0 ... 99] = 1};

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main()
{
    int m = 3;
    int n = 2;
    Solution s;
    cout << s.uniquePaths(m, n) << endl;
}