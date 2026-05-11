class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int pilesSz = piles.size();
        int mx = -1;

        if (pilesSz == 1) return calcCeil(piles[0], h);

        for (int i = 0; i < pilesSz; i++) {
            mx = max(mx, piles[i]);
        }

        if (pilesSz == h) return mx;
        int i = 0;
        int j = mx;
        while (i < j) {
            int totHrs = 0;
            int k = i + (j - i) / 2;
            for (int idx = 0; idx < pilesSz; idx++) {
                totHrs += calcCeil(piles[idx], k);
            }
            if (totHrs <= h) {
                j = k;
            }
            else i = k + 1;
        }

        return i;
    }
private:
    int calcCeil(int dz, int dd) {
        if (dz % dd == 0) return dz / dd;
        else return (dz / dd) + 1;
    }
};
