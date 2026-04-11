class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // set for alr seen tripls?
        //-1,0,1,2,-1,-4
        // sort
        //-4,-1,-1,0,1,2
        // i     k     j
        //-4,-1,-1,0,1,2
        //    i  k     j -> -1,-1,2
        //-4,-1,-1,0,1,2
        //    i    k   j
        //-4,-1,-1,0,1,2
        //    i    k j   -> -1,0,1
        //-4,-1,-1,0,1,2
        //    i  k j
        // loop ends since i k j will overlap
        sort(nums.begin(), nums.end());
        int outer = 0;
        int numsSz = nums.size();
        vector<vector<int>> result;
        while (outer < numsSz) {
            while (outer > 0 && nums[outer] == nums[outer-1]) {
                outer++;
            }

            int left = outer+1;
            int right = numsSz-1;

            while (left < right) {
                int sum = nums[outer] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                }

                else if (sum > 0) {
                    right--;
                }

                else {
                    result.push_back({nums[outer], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right+1]) {
                        right--;
                    }
                }
            }

            outer++;

        }

        return result;
    }
};

