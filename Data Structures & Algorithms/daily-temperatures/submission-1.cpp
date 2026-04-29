class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int inpSz = temperatures.size();
        vector<int> stk;
        vector<int> ans(inpSz, 0);

        for (int i = 0; i < inpSz; i++) {
            if (!stk.empty()) {
                while (!stk.empty() && temperatures[i] > temperatures[stk.back()]) {
                    int idx = stk.back();
                    ans[idx] = (i - idx);
                    stk.pop_back();
                }
            }
            stk.push_back(i);
        }
        return ans;
    }
};
