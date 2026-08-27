class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.size() < k)
            return {};

        std::vector<int> maxNums;
        maxNums.reserve(nums.size() - k + 1);

        std::deque<int> buffer;
        
        for (std::size_t i{}; i < nums.size(); ++i)
        {
            if (!buffer.empty() && (buffer.front() + k) <= i)
                buffer.pop_front();

            while (!buffer.empty() && nums[buffer.back()] <= nums[i])
                buffer.pop_back();

            buffer.push_back(i);

            if (i >= k - 1)
                maxNums.push_back(nums[buffer.front()]);
        }

        return maxNums;
    }
};
