class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> result{};
        auto appendResult = [&result](std::vector<int> params)
        {
            if (std::ranges::find_if(result.begin(), result.end(), [&params](const std::vector<int>& element)
            {
                return std::equal(params.begin(), params.end(), element.begin(), element.end());
            }) != result.end())
                return;

            result.emplace_back(std::move(params));
        };

        std::sort(nums.begin(), nums.end());

        for (std::size_t i{0}; i < nums.size(); ++i)
        {
            int target = -nums[i];
            for (std::size_t l = i + 1, r = nums.size() - 1; l < r;)
            {
                if (target > (nums[l] + nums[r]))
                    ++l;
                else if (target < (nums[l] + nums[r]))
                    --r;
                else
                {
                    appendResult({nums[i], nums[l], nums[r]});
                    --l;
                }
            }
        }

        return result;
    }
};
