class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), inner(9);
        
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                int inner_idx = (i / 3) * 3 + (j / 3);
                if (rows[i].contains(board[i][j]) || cols[j].contains(board[i][j]) || inner[inner_idx].contains(board[i][j])) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                inner[inner_idx].insert(board[i][j]);
            }
        }

        return true;
    }
};
