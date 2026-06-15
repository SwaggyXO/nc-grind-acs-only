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
    int dfs(TreeNode* root, int &k, int &ans) {
        if (!root) return 1;
        if (k == 0) return ans;
        dfs(root->left, k, ans);
        k-=1;
        if (k == 0) {
            ans = root->val;
            return ans;
        }
        dfs(root->right, k, ans);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        return dfs(root, k, ans);
    }
};
