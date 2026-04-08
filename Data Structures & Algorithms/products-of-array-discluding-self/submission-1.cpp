class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // first approach - taking product of all nums - keep final
        // iterate over nums - divide final prod / nums - store result
        // in output arr. return output arr once done.
        // solving follow-up: O(n) time without division
        // I see a pattern - the products are kind of rolling..
        // not sure how to explain this, but see:
        // for [1,2,4,6]:
        // prod at idx 0 = nums[1]*nums[2]*nums[3]
        // then for idx 1,2,3 -> always n-1 elements and
        // 2,3,0;3,0,2;0,1,2 - not sure how to formalize this..

        int numsLen = nums.size();
        vector<int> result(numsLen, 0);

        int prefixProd = 1;
        for (int i = 0; i < numsLen; i++) {
            result[i] = prefixProd;
            prefixProd *= nums[i];
        }

        for (auto x:result) cout << x << " ";

        int suffixProd = 1;
        for (int i = numsLen - 1; i >= 0; i--) {
            result[i] *= suffixProd;
            suffixProd *= nums[i];
        }

        for (auto x:result) cout << x << " ";

        return result;
    }
};
