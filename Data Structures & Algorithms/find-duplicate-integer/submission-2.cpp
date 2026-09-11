class Solution {
public:
    int findDuplicate(std::vector<int>& nums)
    {
        if (nums.empty())
            return -1;

        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int newSlow = 0;
        while (newSlow != slow)
        {
            slow = nums[slow];
            newSlow = nums[newSlow];
        }

        return slow;
    }
};
