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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        TreeNode *root = buildTreeHelper(preorder, inorder);

        return root;
    }

    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> inorder)
    {

        int root_val = preorder[0];
        preorder.erase(preorder.begin());

        TreeNode *root = new TreeNode(root_val);
        // cout << root_val << endl;
        // for (int x : inorder)
        //     cout << x << " ";
        int inorder_idx = searchInorder(inorder, root_val);
        // cout << endl;
        // cout << inorder_idx << endl;
        if (inorder.size() == 1)
        {
            return root;
        }

        if (preorder.size() > 0)
        {
            vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin() + inorder_idx);
            if (leftInorder.size() > 0)
                root->left = buildTreeHelper(preorder, leftInorder);

            vector<int> rightInorder = vector<int>(inorder.begin() + inorder_idx + 1, inorder.end());
            if (rightInorder.size() > 0)
                root->right = buildTreeHelper(preorder, rightInorder);
        }

        return root;
    }

    int searchInorder(vector<int> inorder, int data)
    {
        for (int i = 0; i < inorder.size(); ++i)
            if (inorder[i] == data)
                return i;

        return -1;
    }
};

/* This function is here just to test buildTree() */
void printInorder(TreeNode *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->val << " ";

    /* now recur on right child */
    printInorder(node->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> preorder = {1, 2};
    // vector<int> inorder = {2, 1};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);
    printInorder(root);
    cout << endl;

    return 0;
}