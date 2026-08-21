class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dpA(n + 1, -1);
        vector<int> dpB(n + 1, -1);
        return max(dfs(0, n - 2, nums, dpA), dfs(1, n - 1, nums, dpB));
    }

    int dfs(int idx, int end, vector<int> &nums, vector<int> &dp) {
        if (idx > end) return 0;
        if (dp[idx] != -1) return dp[idx];
        return dp[idx] = max(nums[idx] + dfs(idx + 2, end, nums, dp), dfs(idx + 1, end, nums, dp));
    }
};
