class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = (matrix.size() * matrix[0].size()) - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;
            int idxI = mid / col;
            int idxJ = mid % col;
            if (matrix[idxI][idxJ] == target) return true;

            if (matrix[idxI][idxJ] > target) {
                j = mid - 1;
            }
            else i = mid + 1;
        }
        return false;
    }
};
