#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        vector<int> flattened;
        for (int i = 0; i < n; ++i)
        {
            flattened.insert(flattened.end(), matrix[i].begin(), matrix[i].end());
        }
        sort(flattened.begin(), flattened.end());

        return flattened[k - 1];
    }
};

/*
1 2 3
2 3 4
3 4 5
*/

int main()
{
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    Solution sol;
    cout << sol.kthSmallest(matrix, k) << endl;
}