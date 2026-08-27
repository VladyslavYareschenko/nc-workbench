class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> num_to_pos;
        for (std::size_t i{}; i < nums.size(); ++i)
        {
            auto num = nums[i];
            auto desiredNum = target - num;
            auto it = num_to_pos.find(desiredNum);

            if (it != num_to_pos.end())
                return {static_cast<int>(it->second), static_cast<int>(i)};

            num_to_pos.emplace(nums[i], static_cast<int>(i));
        }

        return {};
    }
};
