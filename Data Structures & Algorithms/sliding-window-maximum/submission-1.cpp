class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Priority-queue/heap method which I was thinking
        // about earlier.

        priority_queue<pair<int,int>> heap;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});

            while (heap.top().second <= i - k) {
                heap.pop();
            }

            if (i >= k - 1) {
                ans.push_back(heap.top().first);
            }
        }
        return ans;
    }
};
