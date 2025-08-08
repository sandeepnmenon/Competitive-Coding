#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void displayMatrix(vector<vector<int>> matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void line()
    {
        cout << "-----------" << endl;
    }

    void rotate(vector<vector<int>> &matrix, int corner_i, int n)
    {
        vector<int> top = {matrix[corner_i].begin() + corner_i, matrix[corner_i].end() - corner_i};
        vector<int> bottom = {matrix[n - corner_i].begin() + corner_i, matrix[n - corner_i].end() - corner_i};
        stack<int> new_bottom, new_top;
        int new_top_corner = matrix[n - corner_i][corner_i];
        // copy top to right
        for (int k = corner_i; k <= n - corner_i; ++k)
        {
            new_bottom.push(matrix[k][n - corner_i]); // the new bottom array
            matrix[k][n - corner_i] = top[k - corner_i];
        }

        // copy new bottom
        for (int k = corner_i; k <= n - corner_i; ++k)
        {
            matrix[n - corner_i][k] = new_bottom.top();
            new_bottom.pop();
        }

        // copy bottom to left
        for (int k = corner_i; k <= n - corner_i; ++k)
        {
            new_top.push(matrix[k][corner_i]);
            matrix[k][corner_i] = bottom[k - corner_i];
        }

        // copy new top
        for (int k = corner_i; k <= n - corner_i; ++k)
        {
            matrix[corner_i][k] = new_top.top();
            new_top.pop();
        }

        matrix[corner_i][corner_i] = new_top_corner;
    }
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size() - 1;
        for (int i = 0; i <= n / 2; ++i)
        {
            rotate(matrix, i, n);
        }
    }
};

int main()
{
    // vector<vector<int>> matrix = {{1, 2}, {3, 4}};
    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> matrix = {{1, 2, 3, 1}, {4, 5, 6, 2}, {7, 8, 9, 3}, {4, 3, 2, 5}};
    vector<vector<int>> matrix = {{1, 2, 3, 1, 2}, {4, 5, 6, 1, 3}, {7, 8, 9, 1, 4}, {4, 3, 2, 1, 5}, {5, 4, 3, 2, 1}};

    Solution s;
    s.displayMatrix(matrix);
    s.rotate(matrix);
    s.line();
    s.displayMatrix(matrix);
}