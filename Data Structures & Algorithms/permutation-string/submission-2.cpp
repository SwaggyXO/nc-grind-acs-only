class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> fS1(26, 0);
        vector<int> fS2(26, 0);

        for (char chr:s1) {
            fS1[chr - 'a']+=1;
        }

        for (int i = 0; i < s1.size(); i++) fS2[s2[i] - 'a']++;

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (fS1[i] == fS2[i]) matches++;
        }

        // cleaner sliding window impl
        // dumdum moment.
        for (int r = s1.size(); r < s2.size(); r++) {
            if (matches == 26) return true;
            
            int idx = s2[r] - 'a';
            fS2[idx]++;
            if (fS2[idx] == fS1[idx]) matches++;
            else if (fS2[idx] == fS1[idx] + 1) matches--;

            idx = s2[r - s1.size()] - 'a';
            fS2[idx]--;
            if (fS2[idx] == fS1[idx]) matches++;
            else if (fS2[idx] == fS1[idx] - 1) matches--;
        }

        return matches == 26;
    }
};
