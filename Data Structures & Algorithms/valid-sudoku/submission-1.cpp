class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (std::size_t j{}; j < board.size(); ++j)
        {
            std::array<bool, 9> rowSeen{false};
            std::array<bool, 9> columnSeen{false};
            std::array<bool, 9> blockSeen{false};

            for (std::size_t i{}; i < board.size(); ++i)
            {
                if (board[j][i] != '.')
                {
                    int num = board[j][i] - '1';
                    if (rowSeen[num])
                        return false;

                    rowSeen[num] = true;
                }

                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    if (columnSeen[num])
                        return false;

                    columnSeen[num] = true;
                }
                
                int blockX = (j / 3) * 3 + i / 3;
                int blockY = (j % 3) * 3 + i % 3;
                if (board[blockX][blockY] != '.')
                {
                    int num = board[blockX][blockY] - '1';
                    if (blockSeen[num])
                        return false;

                    blockSeen[num] = true;
                }
            }
        }

        return true;
    }
};
