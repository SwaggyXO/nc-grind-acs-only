class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int i = 0;
        int j = 1;

        while (j < prices.size()) {
            res = max(res, prices[j] - prices[i]);
            if (prices[j] < prices[i]) {
                i=j;
            }
            j++;
        }

        return res;
    }
};