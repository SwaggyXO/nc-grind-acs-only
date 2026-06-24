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

//    -15
//    /  \
//   10  20
//      /  \
//    15    5
//   /
// -5
// what am i looking for at each node?
// if i am -15 - i want to know the sum from left and right sub-trees?
// upd max if it's bigger than it, go left, then right.
// at 10 - do the same.
// at each node, i want to know the max sum, built by traversing it's sub-trees.
// then i add the current node's value, and check if sum is greater than current stored max.
// refinement: i want the max sum starting from EACH node, unaffected by globals?
class Solution {
public:
    pair<int, int> dfs(TreeNode* root, int &mxSum) {
        // if (!root) return 0;
        // dfs(root->left, sum, mxSum);
        // sum += root->val;
        // mxSum = max(mxSum, sum);
        // dfs(root->right, sum, mxSum);
        // return mxSum;
        if (!root) return {0, 0};
        int sum = root->val;
        // int mxSum = INT_MIN;
        int leftSum = dfs(root->left, mxSum).first;
        int rightSum = dfs(root->right, mxSum).first;
        // (0,0); (0,0); (7,2); {20, 0}; {0, 0}; {0, 1}; {13, 5}; {24, 26};
        sum += leftSum + rightSum; // 7; 2; 20; 24; 13; 5; 26; 55;
        mxSum = max(sum, mxSum); // 7; 7; 20; 24; 24; 24; 26; 55;
        return {max(max(root->val + leftSum, 0), max(root->val + rightSum, 0)), mxSum}; // {7,7}; {2,7}; {20,20}; {24,24}; {13, 24}; {5, 24}; {26, 26}; {55, 55};
    }
    int maxPathSum(TreeNode* root) {
        // int mxSum = INT_MIN;
        // int sum = 0;
        // return dfs(root, sum, mxSum);
        int mxSum = INT_MIN;
        return dfs(root, mxSum).second;
    }
};
