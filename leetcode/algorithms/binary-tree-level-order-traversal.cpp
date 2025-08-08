#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        vector<vector<int>> levels;
        if (root == nullptr)
            return vector<vector<int>>{};
        q.push(make_pair(root, 1));
        vector<int> cur_level_vals;
        int cur_level = 1;
        while (!q.empty())
        {
            pair<TreeNode *, int> node = q.front();
            if (node.first->left)
                q.push(make_pair(node.first->left, node.second + 1));
            if (node.first->right)
                q.push(make_pair(node.first->right, node.second + 1));
            if (node.second == cur_level + 1)
            {
                levels.push_back(cur_level_vals);
                cur_level_vals.clear();
                cur_level += 1;
            }
            cur_level_vals.push_back(node.first->val);

            q.pop();
        }
        levels.push_back(cur_level_vals);

        return levels;
    }
};

int main()
{
    Solution sol;
    // TODO: Write driver code
    return 0;
}