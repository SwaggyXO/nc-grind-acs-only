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
        if (!p && !q) return true;
        if (!p || !q) return false;

        if (p->val != q->val) return false;
        bool isLeftOk = isSameTree(p->left, q->left);
        bool isRightOk = isSameTree(p->right, q->right);

        if (!isLeftOk || !isRightOk) return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // thought it would be easier with iterative
        // ended up implementing recursive first.
        // i don't even understand it fully yet 💀

        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;

        if (root->val == subRoot->val) {
            if (isSameTree(root, subRoot)) {
                return true;
            }
        }

        bool isPresentInLeft = isSubtree(root->left, subRoot);
        bool isPresentInRight = isSubtree(root->right, subRoot);

        if (isPresentInLeft || isPresentInRight) return true;
        return false;
    }
};
