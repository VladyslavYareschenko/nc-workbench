class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        std::vector<int> prefix(nums.size(), 1);
        std::vector<int> suffix(nums.size(), 1);
        
        for (std::size_t i{}; i < nums.size(); ++i)
        {
            prefix[i] = i == 0 ? nums.front() : nums[i] * prefix[i - 1];
            std::size_t j = nums.size() - i - 1;
            suffix[j] = j == (nums.size() - 1) ? nums.back() : nums[j] * suffix[j + 1];
        }    

        std::vector producs(nums.size(), 0);
        for (std::size_t i{}; i < nums.size(); ++i)
        {
            producs[i] = (i == 0 ? 1 : prefix[i - 1]) * (i == (nums.size() - 1) ? 1 : suffix[i + 1]);
        }

        return producs;
    }
};
