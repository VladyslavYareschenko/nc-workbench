class Solution {
public:
    int findDuplicate(std::vector<int>& nums)
    {
        for (int num : nums)
        {
            auto pos = std::abs(num);
            if (nums[pos] < 0)
                return pos;
            nums[pos] = -std::abs(nums[pos]);
        }

        return -1;
    }
};
