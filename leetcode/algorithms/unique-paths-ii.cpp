#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int grid[100][100] = {1};

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    continue;
                }
                if (i == 0 and j > 0)
                    grid[i][j] = grid[i][j - 1];
                else if (j == 0 and i > 0)
                    grid[i][j] = grid[i - 1][j];
                else if (i == 0 and j == 0)
                    grid[i][j] = 1;
                else
                {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                }
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    // vector<vector<int>> obstacleGrid = {{0, 1}, {0, 0}};

    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}