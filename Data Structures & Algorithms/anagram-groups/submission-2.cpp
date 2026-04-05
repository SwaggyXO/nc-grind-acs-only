class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // init - empty result container - map<str, set<str>>
        // iter through strs -> init set before inserting the str as key
        // in the map.
        // if key is not seen, add it, if it is seen, update the set
        // voila!
        // not voila..
        // use the logic from valid anagrams and the fact
        // that strs[i] is fixed to 26 chars only.
        // create a hash by adding the char values in int, and use it as
        // the key for the groups.
        // now voila!
        // can be optimized I believe, need to think more.

        unordered_map<string, vector<string>> strsMap;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            string currStr = strs[i];
            sort(currStr.begin(), currStr.end());
            if (strsMap.find(currStr) != strsMap.end()) {
                strsMap[currStr].push_back(strs[i]);
                continue;
            }
            vector<string> tmp;
            tmp.push_back(strs[i]);
            strsMap[currStr] = tmp;
        }
        for (auto x:strsMap) {
            result.push_back(x.second);
        }

        return result;
    }
};
