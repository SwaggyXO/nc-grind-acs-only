class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int numsLen = nums.size();
        set<int> numSet;

        for (int i = 0; i < numsLen; i++) {
            numSet.insert(nums[i]);
        }
                
        int res = 0;
        int curr = 1;
        for (auto num:numSet) {
            if (numSet.contains(num+=1)) {
                curr++;
            }
            else {
                res = max(curr, res);
                curr = 1;
            }
        }
        return res;
    }
};
