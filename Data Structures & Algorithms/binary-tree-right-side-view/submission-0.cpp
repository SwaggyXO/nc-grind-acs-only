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
        vector<int> ans;
        if (!root) return ans;

        queue<pair<TreeNode*, int>> nodes;
        nodes.push({root, 0});
        int lvl = 0;
        int req = 0;

        while(!nodes.empty()) {
            int nodesLen = nodes.size();
            for (int i = 0; i < nodesLen; i++) {
                TreeNode* curr = nodes.front().first;
                int currLvl = nodes.front().second;
                if (!curr) {
                    nodes.pop();
                    continue;
                }
                if (currLvl == req) {
                    ans.push_back(curr->val);
                    req++;
                }
                bool rightPresent = false;
                if (curr->right) {
                    rightPresent = true;
                    nodes.push({curr->right, req});
                }

                if (curr->left) {
                    if (rightPresent) nodes.push({curr->left, lvl});
                    else nodes.push({curr->left, req});
                }
                nodes.pop();
            }
            lvl++;
        }
        return ans;
    }
};