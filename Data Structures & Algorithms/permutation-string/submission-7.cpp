class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // init freq arr for s1 and s2
        // init matches = 26 or 0
        // matches is basically an optimization over raw freqS1==freqS2
        // check. it reduces the heavier freq arr comparison with
        // a variable, which essentially denotes the same thing.
        // idea: we basically need to check for char matches in s1 while
        // iterating over s2 with a fixed window length of s1.size().
        // we return as soon as we find a match.
        // else we exit and conclude that there is no match.
        // forgot to init match using the 26 len for loop.

        if (s1.size() > s2.size()) return false;

        int freqS1[26] = {0};
        int freqS2[26] = {0};
        int matches = 26;

        for (int i = 0; i < s1.size(); i++) {
            freqS1[s1[i] - 'a']++;
        }

        for (int i = 0; i < s1.size(); i++) {
            freqS2[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freqS1[i] != freqS2[i]) matches--;
        }

        if (matches == 26) return true;

        int i = 0;
        int j = s1.size();

        while (j < s2.size()) {
            if (matches == 26) return true;
            int idxJ = s2[j] - 'a';
            freqS2[idxJ]++;
            if (freqS2[idxJ] == freqS1[idxJ]) matches+=1;
            else if (freqS2[idxJ] == freqS1[idxJ] + 1) matches-=1;
            int idxI = s2[i] - 'a';
            freqS2[idxI]--;
            if (freqS2[idxI] == freqS1[idxI]) matches+=1;
            else if (freqS2[idxI] == freqS1[idxI] - 1) matches-=1;
            i++;
            j++;
        }
        return matches == 26;
    }
};
