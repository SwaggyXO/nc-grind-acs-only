class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        vector<int> freq(256, 0);
        int i = 0;
        int j = i;
        int res = 0;

        while (j < s.size()) {
            freq[(unsigned char)s[j]] += 1;
            while(freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }
            res = max(res, (j - i) + 1);
            j++;
        }

        // res = max(res, (j - i) + 1);
        return res;
    }
};
