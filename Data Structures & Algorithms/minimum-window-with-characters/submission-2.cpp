class Solution {
public:
    string minWindow(string s, string t) {
        // need X:1, Y:1, Z:1
        // freq[X=1,Y=1,Z=1]
        int freqT[128] = {0};
        int freqS[128] = {0};
        int formed = 0;
        int required = 0;
        pair<int, int> ans = {0, 0};
        int bestLen = INT_MAX;

        for (int i = 0; i < t.size(); i++) {
            freqT[t[i]]++;
            if (freqT[t[i]] == 1) {
                required++;
            }
        }

        int i = 0;
        int j = 0;

        while (j < s.size()) {
            int idxJ = s[j];
            freqS[idxJ]++;
            if (freqT[idxJ] && freqS[idxJ] == freqT[idxJ]) formed++;

            while (formed == required) {
                if (j - i < bestLen) {
                    ans.first = i;
                    ans.second = j;
                    bestLen = j - i + 1;
                }
                int idxI = s[i];
                freqS[idxI]--;
                if (freqS[idxI] == freqT[idxI] - 1) formed--;
                i++;
            }
            j++;
        }
        if (bestLen == INT_MAX) return "";
        return s.substr(ans.first, bestLen);
    }
};
