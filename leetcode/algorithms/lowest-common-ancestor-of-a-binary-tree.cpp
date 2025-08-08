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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        vector<TreeNode *> p_dfs, q_dfs;
        dfs(root, p->val, p_dfs);
        dfs(root, q->val, q_dfs);

        int i = 0;
        while (i < p_dfs.size() and i < q_dfs.size() and p_dfs[i]->val == q_dfs[i]->val)
        {
            i++;
        }
        return p_dfs[i - 1];
    }

    bool dfs(TreeNode *root, int x, vector<TreeNode *> &path)
    {
        if (root == NULL)
        {
            return false;
        }
        path.push_back(root);

        if (root->val == x)
        {
            return true;
        }

        if (dfs(root->left, x, path) or dfs(root->right, x, path))
        {
            return true;
        }
        else
        {
            path.pop_back();
            return false;
        }
    }
};

class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL or root->val == p->val or root->val == q->val)
        {
            return root;
        }

        TreeNode *left_lca = lowestCommonAncestor(root->left, p, q);
        TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);

        if (left_lca and right_lca)
        {
            return root;
        }
        else
        {
            return left_lca ? left_lca : right_lca;
        }
    }
};

int main()
{
    Solution sol;
    // TODO: Write driver code
    vector<int> lorder = {3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4};
    return 0;
}