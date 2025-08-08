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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> stack;
        getkthSmallest(root, k, stack);
        return stack[stack.size() - 1];
    }

    void getkthSmallest(TreeNode *root, int k, vector<int> &stack)
    {
        if (root == nullptr)
            return;

        getkthSmallest(root->left, k, stack);
        if (stack.size() < k)
            stack.push_back(root->val);
        if (stack.size() == k)
            return;
        getkthSmallest(root->right, k, stack);
    }
};

int main()
{
    Solution sol;
    // TODO: Write driver code
    return 0;
}