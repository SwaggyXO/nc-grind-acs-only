class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> fS1(26, 0);
        vector<int> fS2(26, 0);

        for (char chr:s1) {
            fS1[chr - 'a']+=1;
        }

        for (int i = 0; i < s1.size(); i++) {
            fS2[s2[i] - 'a']+=1;
        }

        if (fS1 == fS2) return true;
        int i = 0;
        int j = s1.size() - 1;

        while (j < s2.size()) {
            fS2[s2[i] - 'a']-=1;
            i++;
            j++;
            fS2[s2[j] - 'a']+=1;
            if (fS1 == fS2) return true;
        }

        return fS1 == fS2;
    }
};
