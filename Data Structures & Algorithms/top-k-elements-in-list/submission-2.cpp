class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> eleFreq;
        map<int, vector<int>, std::greater<int>> highFreqEl;
        vector<int> result;
        for (auto num:nums) {
            eleFreq[num]++;
        }

        for (auto ele:eleFreq) {
            if (highFreqEl.find(ele.second) != highFreqEl.end()) {
                highFreqEl[ele.second].push_back(ele.first);
                continue;
            }
            vector<int> tmp;
            tmp.push_back(ele.first);
            highFreqEl[ele.second] = tmp; 
        }

        for (auto ele: highFreqEl) {
            if (k == 0) break;
            int currVecSz = ele.second.size();
            result.insert(result.end(), ele.second.begin(), ele.second.begin() + min(k, currVecSz));
            k -= currVecSz;
        }

        if (result.size() == 0) return nums;

        return result;
    }
};
