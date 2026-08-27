class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> result{};

        std::sort(nums.begin(), nums.end());

        for (std::size_t i{0}; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            for (std::size_t l = i + 1, r = nums.size() - 1; l < r;)
            {
                if (target > (nums[l] + nums[r]))
                    ++l;
                else if (target < (nums[l] + nums[r]))
                    --r;
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;

                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                }
            }
        }

        return result;
    }
};
