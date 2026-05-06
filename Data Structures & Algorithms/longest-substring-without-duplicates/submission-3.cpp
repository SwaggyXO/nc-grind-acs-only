class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        // optimization: make i jump instead of removing 1 by 1
        // we don't need to maintain the freq state
        // and it's way faster.
        vector<int> lastSeen(256, -1);
        int i = 0;
        int j = i;
        int res = 0;

        while (j < s.size()) {
            if (lastSeen[s[j]] >= i) {
                i = max(i, lastSeen[s[j]] + 1);
            }
            lastSeen[(unsigned char)s[j]] = j;
            res = max(res, (j - i) + 1);
            j++;
        }
        return res;
    }
};
