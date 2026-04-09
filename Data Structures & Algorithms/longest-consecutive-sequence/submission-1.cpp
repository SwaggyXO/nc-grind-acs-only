class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int numsLen = nums.size();
        map<int, int> numsMap;

        for (int i = 0; i < numsLen; i++) {
            numsMap[nums[i]]++;
        }
                
        int res = 0;
        int curr = 0;
        int prev = 0;
        for (auto num:numsMap) {
            if (res == 0 && curr == 0 && prev == 0) {
                res = 1;
                curr = 1;
                prev = num.first;
                continue;
            }
            if (num.first - prev != 1) {
                res = max(curr, res);
                curr = 0;
            }
            prev = num.first;
            curr++;
        }
        res = max(curr, res);
        return res;
    }
};
