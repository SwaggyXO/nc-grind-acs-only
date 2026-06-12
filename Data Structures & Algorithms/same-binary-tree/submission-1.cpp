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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // cases: node vs no node; diff val;
        // dfs and any sort of traversal for rec soln
        // level order works too.
        // impl both for prac.
        if (!p && !q) return true;
        if (!p || !q) return false;
        queue<TreeNode*> pq;
        pq.push(p);
        queue<TreeNode*> qq;
        qq.push(q);

        while (!pq.empty() && !qq.empty()) {
            int pqLen = pq.size();
            int qqLen = qq.size();

            for (int i = 0; i < pqLen; i++) {
                TreeNode* currPQ = pq.front();
                TreeNode* currQQ = qq.front();
                if (!currPQ && !currQQ) {
                    pq.pop();
                    qq.pop();
                    continue;
                }
                if (currPQ->val != currQQ->val) return false;
                if (!currPQ->left && currQQ->left) return false;
                if (currPQ->left && !currQQ->left) return false;
                if (!currPQ->right && currQQ->right) return false;
                if (currPQ->right && !currQQ->right) return false;
                pq.push(currPQ->left);
                pq.push(currPQ->right);
                pq.pop();
                qq.push(currQQ->left);
                qq.push(currQQ->right);
                qq.pop();
            }
        }

        return true;
    }
};
