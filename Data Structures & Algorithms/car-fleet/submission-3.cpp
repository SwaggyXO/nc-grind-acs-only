class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> posspeed;
        for (int i = 0; i < position.size(); i++) {
            posspeed.push_back({position[i], speed[i]});
        }
        sort(posspeed.begin(), posspeed.end(), [](const pair<int, int>& prA, const pair<int, int>& prB) {
            return prA.first > prB.first;
        });
        
        int ans = 0;
        double last_time = INT_MIN;
        for (int i = 0; i < position.size(); i++) {
            int rem_dist = target - posspeed[i].first;
            int ispeed = posspeed[i].second;
            double curr_time = (double)rem_dist / ispeed;
            if (curr_time > last_time) {
                ans++;
                last_time = curr_time;
            }
        }
        return ans;
    }
};
