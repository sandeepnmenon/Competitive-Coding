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
    void getNodesatDepth(TreeNode *root, int depth, vector<TreeNode *> &res)
    {
        if (root == NULL)
            return;
        if (depth == 1)
        {
            if (root != NULL)
                res.push_back(root);
            return;
        }

        getNodesatDepth(root->left, depth - 1, res);
        getNodesatDepth(root->right, depth - 1, res);
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *nroot = new TreeNode(val);
            nroot->left = root;

            return nroot;
        }
        vector<TreeNode *> res;
        getNodesatDepth(root, depth - 1, res);
        for (TreeNode *x : res)
        {
            TreeNode *lsub = new TreeNode(val);
            TreeNode *rsub = new TreeNode(val);
            lsub->left = x->left;
            rsub->right = x->right;
            x->left = lsub;
            x->right = rsub;
        }

        return root;
    }
};