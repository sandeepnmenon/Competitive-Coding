#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void explore(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }
        if (grid[i][j] == '0')
        {
            return;
        }
        // visited[i][j] = true;
        grid[i][j] = '0';
        explore(grid, i + 1, j, m, n);
        explore(grid, i - 1, j, m, n);
        explore(grid, i, j + 1, m, n);
        explore(grid, i, j - 1, m, n);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        int num_islands = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    num_islands++;
                    explore(grid, i, j, m, n);
                }
            }
        }

        return num_islands;
    }
};

int main()
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};

    Solution sol;
    cout << sol.numIslands(grid) << endl;
}