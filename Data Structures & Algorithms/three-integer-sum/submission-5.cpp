class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> result{};

        std::sort(nums.begin(), nums.end());

        for (std::size_t i{0}; i < nums.size(); ++i)
        {
            int target = -nums[i];
            for (std::size_t l = i + 1, r = nums.size() - 1; l < r;)
            {
                if (target > (nums[l] + nums[r]))
                    --r;
                else if (target < (nums[l] + nums[r]))
                    ++l;
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                }
            }
        }

        return result;
    }
};
