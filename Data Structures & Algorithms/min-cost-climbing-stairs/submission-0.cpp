class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size(), -1);
        return min(recu(0, cost, dp), recu(1, cost, dp));
    }
private:
    int recu(int idx, vector<int> &cost, vector<int> &dp) {
        if (idx >= cost.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        return dp[idx]=min(cost[idx] + recu(idx + 2, cost, dp), cost[idx] + recu(idx + 1, cost, dp));
    }
};
