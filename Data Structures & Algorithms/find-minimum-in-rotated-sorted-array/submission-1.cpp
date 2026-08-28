class Solution {
public:
    int findMin(std::vector<int> &nums)
    {
        if (nums.empty())
            return -1;

        if (nums.size() <= 2)
            return std::min(nums.front(), nums.back());

        std::size_t l{};
        std::size_t r{nums.size() - 1};

        while (l < r)
        {
            std::size_t mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return nums[l];
    }
};
