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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        int currPVal = p->val;
        int currQVal = q->val;
        int currRootVal = root->val;

        if ((currPVal <= currRootVal && currQVal >= currRootVal) || (currQVal <= currRootVal && currPVal >= currRootVal)) return root;

        if (currPVal < currRootVal) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return lowestCommonAncestor(root->right, p, q);
    }
};
