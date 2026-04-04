class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int numsLen = nums.size();
        unordered_map<int, int> numMap;
        for (int i = 0; i < numsLen; i++) {
            numMap[nums[i]]++;
        }

        for (auto numItr:numMap) {
            if (numItr.second >= 2) return 1;
        }

        return 0;
    }
};