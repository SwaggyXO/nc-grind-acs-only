class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // def revisit and sit with this problem longer
        // new to such control flows. really mind numbing.
        deque<int> dq;
        vector<int> ans;

        for (int j = 0; j < nums.size(); j++) {
            // remove smaller elements from the back
            // because they will never be a valid candidate
            // for being the greatest if we already see a bigger
            // number. this is like nums in descending order
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            if (dq.front() <= j - k) {
                dq.pop_front();
            }

            if (j >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
