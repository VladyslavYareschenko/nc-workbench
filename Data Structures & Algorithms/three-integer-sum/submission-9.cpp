class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> result{};

        std::sort(nums.begin(), nums.end());

        for (std::size_t i{0}; i < nums.size(); ++i)
        { 
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            for (std::size_t l{i + 1}, r{nums.size() - 1}; l < r;)
            {
                if ((nums[l] + nums[r]) > target)
                    --r;
                else if ((nums[l] + nums[r]) < target)
                    ++l;
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    --r;
                    ++l;

                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                }
            }
        }

        return result;
    }
};
