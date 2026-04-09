class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // the optimal idea:
        // instead of checking on every number,
        // only start counting when you find a possible seq. start
        // i.e. the set not having selectedNum - 1 -> that means
        // there is a possibility this number could lead to the
        // result.
        int numsLen = nums.size();
        set<int> numSet;

        for (int i = 0; i < numsLen; i++) {
            numSet.insert(nums[i]);
        }

        int res = 0;
        for (int num : numSet) {
            if (!numSet.contains(num - 1)) {
                int curr = 1;
                int next = num + 1;

                while (numSet.contains(next)) {
                    curr++;
                    next++;
                }

                res = max(res, curr);
            }
        }
        return res;
    }
};
