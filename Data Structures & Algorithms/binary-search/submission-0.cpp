class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int found = -1;

        for (std::size_t l{}, r{nums.size()}; l < r;)
        {
            std::size_t mid = l + (r - l) / 2;

            int num = nums[mid];
            if (num == target)
            {
                found = static_cast<int>(mid);
                break;
            }
            else if (num > target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return found;
    }
};
