class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        std::optional<std::reference_wrapper<std::vector<int>>> rowRef;
        {
            std::size_t top{};
            std::size_t bottom(matrix.size());

            while (top < bottom)
            {
                std::size_t mid = top + (bottom - top) / 2;

                auto& row = matrix[mid];
                if (!row.empty() && row.front() <= target && target <= row.back())
                {
                    rowRef = {std::ref(row)};
                    break;
                }
                else if (!row.empty() && row.front() > target)
                {
                    bottom = mid;
                }
                else if (!row.empty() && row.back() < target)
                {
                    top = mid + 1;
                }
            }
        }

        if (!rowRef)
            return false;

        {
            const auto& row = rowRef->get();

            std::size_t l{};
            std::size_t r{row.size()};

            while (l < r)
            {
                std::size_t mid = l + (r - l) / 2;

                if (row[mid] == target)
                {
                    return true;
                }
                else if (row[mid] > target)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        return false;
    }
};
