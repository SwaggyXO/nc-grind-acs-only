class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int inpSz = temperatures.size();
        vector<pair<int, int>> stk;
        vector<int> ans(inpSz, 0);

        for (int i = 0; i < inpSz; i++) {
            if (!stk.empty()) {
                while (!stk.empty() && temperatures[i] > stk.back().first) {
                    int idx = stk.back().second;
                    ans[idx] = (i - idx);
                    stk.pop_back();
                }
            }
            stk.push_back({temperatures[i], i});
        }
        return ans;
    }
};
