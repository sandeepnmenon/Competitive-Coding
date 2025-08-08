#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isWord(vector<vector<char>> &board, string word, int widx, int i, int j, int m, int n, bool visited[][6])
    {
        if (visited[i][j])
            return false;

        if (board[i][j] != word[widx])
        {
            // cout << board[i][j] << " " << word[widx] << endl;
            return false;
        }
        if (widx == word.size() - 1)
        {
            // cout << "matched " << board[i][j] << " " << word[widx] << endl;
            return true;
        }
        // cout << word[widx] << " " << i << " " << j << endl;
        bool ans = false;
        if (i < m)
        {
            visited[i][j] = true;
            ans = ans or isWord(board, word, widx + 1, i + 1, j, m, n, visited);
            if (ans)
                return ans;
            visited[i][j] = false;
        }
        if (i > 0)
        {
            visited[i][j] = true;
            ans = ans or isWord(board, word, widx + 1, i - 1, j, m, n, visited);
            if (ans)
                return ans;
            visited[i][j] = false;
        }
        if (j < n)
        {
            visited[i][j] = true;
            ans = ans or isWord(board, word, widx + 1, i, j + 1, m, n, visited);
            if (ans)
                return ans;
            visited[i][j] = false;
        }
        if (j > 0)
        {
            visited[i][j] = true;
            ans = ans or isWord(board, word, widx + 1, i, j - 1, m, n, visited);
            if (ans)
                return ans;
            visited[i][j] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        bool ans = false;
        int m = board.size() - 1, n = board[0].size() - 1;

        bool visited[6][6];
        fill(&visited[0][0], &visited[0][0] + sizeof(visited) /* / sizeof(flags[0][0]) */, false);

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    ans = ans or isWord(board, word, 0, i, j, m, n, visited);
                    fill(&visited[0][0], &visited[0][0] + sizeof(visited) /* / sizeof(flags[0][0]) */, false);
                }
                if (ans)
                    break;
            }
            if (ans)
                break;
        }
        // cout << endl;
        return ans;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";
    // string word = "SEE";
    // string word = "ABCB";

    Solution s;
    cout << s.exist(board, word) << endl;
}