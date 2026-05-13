class Solution {
public:
    int findMin(vector<int> &nums) {
        int numsSz = nums.size();
        int mn = INT_MAX;
        // does this actually pass?
        for (int i = 0; i < numsSz; i++) {
            mn = min(mn, nums[i]);
        }
        return mn;
    }
};
