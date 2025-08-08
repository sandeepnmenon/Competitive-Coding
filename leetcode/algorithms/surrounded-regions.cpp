#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<char>> board, int i, int j, bool visited[][200])
    {
        int m = board.size() - 1, n = board[0].size() - 1;
        if (i < 0 or j < 0 or i > m or j > n)
        {
            return;
        }
        if (board[i][j] == 'X' or visited[i][j])
        {
            return;
        }

        visited[i][j] = true;
        dfs(board, i + 1, j, visited);
        dfs(board, i, j + 1, visited);
        dfs(board, i - 1, j, visited);
        dfs(board, i, j - 1, visited);
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        // vector<vector<bool>> visited
        bool visited[200][200] = {{false}};
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O' and !visited[i][0])
            {
                dfs(board, i, 0, visited);
            }
            if (board[i][n - 1] == 'O' and !visited[i][n - 1])
            {
                dfs(board, i, n - 1, visited);
            }
        }

        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O' and !visited[0][j])
            {
                dfs(board, 0, j, visited);
            }
            if (board[m - 1][j] == 'O' and !visited[m - 1][j])
            {
                dfs(board, m - 1, j, visited);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O' and !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    // vector<vector<char>> board = {{'X'}};
    vector<vector<char>> board = {{'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'}, {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'}};
    Solution s;
    s.solve(board);
    for (vector<char> row : board)
    {
        for (char el : row)
        {
            cout << el << ' ';
        }
        cout << endl;
    }
}