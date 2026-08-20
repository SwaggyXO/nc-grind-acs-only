class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return max(dfs(0, nums, dp), dfs(1, nums, dp));
    }

    int dfs(int idx, vector<int> &nums, vector<int> &dp) {
        if (idx >= nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        return dp[idx]=max(nums[idx] + dfs(idx + 2, nums, dp), nums[idx] + dfs(idx + 3, nums, dp));
    }
};
