/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool dfs(TreeNode* root, int rangeMin, int rangeMax) {
        if (!root) return true;
        if (root->val <= rangeMin || root->val >= rangeMax) return false;
        return dfs(root->left, rangeMin, root->val) && dfs(root->right, root->val, rangeMax);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return dfs(root, INT_MIN, INT_MAX);
    }
};
