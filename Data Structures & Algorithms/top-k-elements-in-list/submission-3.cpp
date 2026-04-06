class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bounded + dense range for k = bucket sort applicable
        // optimal as compared to my prev solution..
        unordered_map<int, int> eleFreq;
        vector<int> result;
        for (auto num:nums) {
            eleFreq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [ele, count]:eleFreq) {
            bucket[count].push_back(ele);
        }

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (auto num:bucket[i]) {
                if (k == 0) break;
                result.push_back(num);
                k--;
            }
        }

        if (result.size() == 0) return nums;
        return result;
        
    }
};
