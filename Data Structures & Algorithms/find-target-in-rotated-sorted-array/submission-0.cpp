class Solution {
public:
    int search(const std::vector<int>& nums, int target)
    {
        if (nums.empty())
            return -1;
    
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        }
    
        if (target >= nums[l] && target <= nums[nums.size() - 1])
        {
            r = nums.size() - 1;
        }
        else
        {
            r = l - 1;
            l = 0;
        }
    
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
                r = m - 1;
            else if (nums[m] < target)
                l = m + 1;
            else
                return m;
        }
    
        return -1;
    }
};
