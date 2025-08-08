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
    bool isValidBST(TreeNode *root)
    {

        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode *root, TreeNode *left, TreeNode *right)
    {
        if (root == NULL)
            return true;

        if (left != NULL and root->val <= left->val)
            return false;

        if (right != NULL and root->val >= right->val)
            return false;

        return isValidBST(root->left, left, root) and
               isValidBST(root->right, root, right);
    }
};

int main()
{
    Solution sol;
    // TODO: Write driver code
    return 0;
}