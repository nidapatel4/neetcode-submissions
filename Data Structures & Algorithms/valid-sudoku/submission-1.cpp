class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int r = 0; r < 9; r++) {

            for(int c = 0; c < 9; c++) {

                char digit = board[r][c];

                if(digit == '.')
                    continue;

                int box = (r / 3) * 3 + (c / 3);

                if(rows[r].count(digit) ||
                   cols[c].count(digit) ||
                   boxes[box].count(digit))
                {
                    return false;
                }

                rows[r].insert(digit);
                cols[c].insert(digit);
                boxes[box].insert(digit);
            }
        }

        return true;
    }
};