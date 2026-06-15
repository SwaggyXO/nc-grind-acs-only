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
    int dfs(TreeNode* root, int &ans, int mx) {
        if (!root) return 0;
        if (root->val >= mx) ans+=1;
        mx = max(root->val, mx);
        dfs(root->left, ans, mx);
        dfs(root->right, ans, mx);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        return dfs(root, ans, root->val);
    }
};