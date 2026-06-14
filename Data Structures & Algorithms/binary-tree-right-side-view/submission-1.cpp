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
    vector<int> rightSideView(TreeNode* root) {
        // we just need the right most node from each lvl.
        // duhhhhh.
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            int nodesLen = nodes.size();
            ans.push_back(nodes.back()->val);
            for (int i = 0; i < nodesLen; i++) {
                TreeNode* curr = nodes.front();
                if (!curr) {
                    nodes.pop();
                    continue;
                }
                if (curr->left) nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right);
                nodes.pop();
            }
        }
        return ans;
    }
};