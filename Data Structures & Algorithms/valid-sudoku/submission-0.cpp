class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                // Превращаем символ цифры в смещение бита (от 0 до 8)
                int val = board[r][c] - '1'; 
                int mask = 1 << val;
                int b_index = (r / 3) * 3 + (c / 3);

                // Если бит уже установлен, значит цифра дублируется
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[b_index] & mask)) {
                    return false;
                }

                // Фиксируем цифру в строке, столбце и малом квадрате
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[b_index] |= mask;
            }
        }
        return true;
    }
};
