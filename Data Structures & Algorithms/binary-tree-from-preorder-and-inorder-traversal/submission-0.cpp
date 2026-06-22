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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 1 2 3 4 - p (r, l, ri)
        // 2 1 3 4 - i (l, r, ri)
        // unable to link the 2 traversals..
        //   1
        //  / \
        // 2   3
        //      \
        //       4
        // wow. worked-examples for the win.
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int rootVal = root->val;
        int partitionSize = 0;
        int i = 0;
        if (!inorder.empty()) {
            while (inorder[i] != rootVal) {
                partitionSize++;
                i++;
            }
        }
        vector<int> leftInorderView(inorder.begin(), inorder.begin() + partitionSize);
        vector<int> rightInorderView(inorder.begin() + partitionSize + 1, inorder.end());
        vector<int> leftPreorderView(preorder.begin() + 1, preorder.begin() + partitionSize + 1);
        vector<int> rightPreorderView(preorder.begin() + partitionSize + 1, preorder.end());
        root->left = buildTree(leftPreorderView, leftInorderView);
        root->right = buildTree(rightPreorderView, rightInorderView);
        return root;
    }
};
