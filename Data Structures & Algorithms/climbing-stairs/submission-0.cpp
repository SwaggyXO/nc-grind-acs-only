class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        if (n <= 1) return 1;
        return memo(n, dp);
    }

private:
    int memo(int n, vector<int> &dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = memo(n - 1, dp) + memo(n - 2, dp);
    }
};
