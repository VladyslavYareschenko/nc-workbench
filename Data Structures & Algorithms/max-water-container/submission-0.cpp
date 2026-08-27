class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int max = 0;

        for (std::size_t l{}, r{heights.size() - 1}; l < r;)
        {
            int width = r - l;
            max = std::max(std::min(heights[l], heights[r]) * width, max);

            heights[r] > heights[l] ? ++l : --r;
        }

        return max;
    }
};
