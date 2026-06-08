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
    void inversion(TreeNode* curr) {
        if (!curr) return;
        TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        inversion(curr->left);
        inversion(curr->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        // 1 2 3 4 5 6 7 - level order traversal basically.
        // lvl 1 - no flip coz root bruh
        // lvl 2 onwards - swap: (first, last), (first + 1, last - 1)
        // and so on.
        // 1 3 2 7 6 5 4
        // recusrion makes is crazy easy.
        // if (!root || (!root->left && !root->right)) return root;
        // queue<TreeNode*> nodes;
        // nodes.push(root);
        // while (!nodes.empty()) {
        //     int levelSize = nodes.size();
        //     for (int i = 0; i < levelSize; i++) {
        //         TreeNode* curr = nodes.front();
        //         TreeNode* temp = curr->left;
        //         curr->left = curr->right;
        //         curr->right = temp;
        //         if (curr->left) nodes.push(curr->left);
        //         if (curr->right) nodes.push(curr->right);
        //         nodes.pop();
        //     }
        // }
        // return root;
        inversion(root);
        return root;
    }
};
