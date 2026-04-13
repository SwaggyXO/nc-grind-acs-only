class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int total = 0;
        int leftMax = height[l];
        int rightMax = height[r];

        while (l < r) {
            if (leftMax < rightMax) {
                int capacity = leftMax - height[l];
                total += capacity > 0 ? capacity : 0;
                l++;
                leftMax = max(leftMax, height[l]);
            }

            else {
                int capacity = rightMax - height[r];
                total += capacity > 0 ? capacity : 0;
                r--;
                rightMax = max(rightMax, height[r]);
            }
        }

        return total;
    }
};
