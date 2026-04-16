class Solution {
public:
    int characterReplacement(string s, int k) {
        // longest repeating substring
        // +
        // substring with K distinct characters
        // excluding the selected character
        // for the repeating substring
        // sliding window makes it so easy.
        // or so i thought. -2hrs.
        int sLen = s.size();
        if (sLen == 1) return 1;
        int i = 0;
        int j = 0;

        int freq[26] = {0};
        int maxFreq = 0;

        int res = 0;
        while (j < sLen) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            
            while ((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            
            res = max(res, (j - i) + 1);
            j++;
        }
        return res;
    }
};
