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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> treeq;
        treeq.push(root);
        treeq.push(NULL);
        vector<int> temp;
        while (!treeq.empty()) {
            TreeNode* curr = treeq.front();
            treeq.pop();
            if (!curr) {
                ans.push_back(temp);
                temp.clear();
                if (!treeq.empty()) {
                    treeq.push(NULL);
                }
            }
            else {
                temp.push_back(curr->val);
                if (curr->left) treeq.push(curr->left);
                if (curr->right) treeq.push(curr->right);
            }
        }

        return ans;
    }
};
