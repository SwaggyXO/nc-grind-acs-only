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
        // cleaner iterative.
        if (!p && !q) return true;
        if (!p || !q) return false;
        queue<pair<TreeNode*, TreeNode*>> pq;
        pq.push({p, q});

        while (!pq.empty()) {
            TreeNode* currp = pq.front().first;
            TreeNode* currq = pq.front().second;
            if (!currp && !currq) {
                pq.pop();
                continue;
            }
            if (!currp || !currq) return false;
            if (currp->val != currq->val) return false;
            pq.push({currp->left, currq->left});
            pq.push({currp->right, currq->right});
            pq.pop();
        }

        return true;
    }
};