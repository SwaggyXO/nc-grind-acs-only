class Solution {
public:
    string minWindow(string s, string t) {
        // the crux here is checking each char's freq individually
        // expand j
        // expand i only when all individual freqs are satisfied.
        // similar logic to maintaining a "matches" kind of var from
        // perm in string. here we keep 2: required and formed.
        // required = no. of unique chars from t.
        // we maintain a bestLen init'd with
        // INT_MAX which is the len of min size valid
        // window we've seen so far.
        // for the final ans, we maintain a pair<i,j> which tracks
        // the best coords. these coords are only updated
        // if we find a better bestLen
        // if we never find a better bestLen, the ans is " "
        int freqS[128] = {0};
        int freqT[128] = {0};
        int required = 0;
        int formed = 0;
        int bestLen = INT_MAX;
        int bestCoord = 0;

        for (char c:t) {
            // directly access since 123 covers all letters
            freqT[c]++;
            if (freqT[c] == 1) required++;
        }

        int i = 0;
        int j = 0;

        while (j < s.size()) {
            freqS[s[j]]++;
            if (freqS[s[j]] == freqT[s[j]]) formed++;

            while (formed == required) {
                if ((j - i) + 1 < bestLen) {
                    bestCoord = i;
                    bestLen = j - i + 1;
                }

                freqS[s[i]]--;
                if (freqS[s[i]] == freqT[s[i]] - 1) formed--;
                i++;
            }
            j++;
        }

        if (bestLen == INT_MAX) return "";

        return s.substr(bestCoord, bestLen);
    }
};
