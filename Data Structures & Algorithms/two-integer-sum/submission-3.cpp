class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // initial thought was
        //     run with the sum var
        //     sub on seeing an element
        //     check with next from arr
        //     fails - because ?? cant formalize but ik because next approach.
        
        // second:
        // build map
        // 4 -> 0
        // 5 -> 1
        // 6 -> 2
        // sum = 10
        // for i -> n:
        //     if exists m[sum - nums[i]]: return m[nums[i]], m[sum - nums[i]]
        
        // forgot about indices! they should be different.
        // looked up: same key diff value map cpp
        // new thought: inverse the key:value - make idx the key and the num
        // at that idx the value? - trying this before multimap
        // hit a roadblock - finding the remaining value isn't as simple.
        // multimap seems like it.
        // confused - how do lookups work for same keys in multimap?
        // how do I filter?
        // googled - is 2 sum possible with multimap in C++? just say yes or no.
        // it said Yes, but unordered_map is preferred.
        // going back to thinking with unordered_map.
        // same algo just instead of picking first ele from the map
        // just use the idx dir - solves the issue of [1, 1] with [5, 5] input.
        
        unordered_map<int, int> elePos;
        for (int i = 0; i < nums.size(); i++) elePos[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (elePos.find(rem) != elePos.end() && i != elePos[rem]) {
                return {i, elePos[rem]};
            }
            else continue;
        }

    }
};
