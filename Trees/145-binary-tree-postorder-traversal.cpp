// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

// Time Complexity: O(n) because every node is visited once

// Space Complexity: O(n) because we create a new vector to store the result

#include <vector>
using namespace std;

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return;

        traverse(root->left, result);
        traverse(root->right, result);
        result.push_back(root->val);
    }
};