class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        std::unordered_set<int> numsSet{nums.begin(), nums.end()};

        std::size_t longest{};

        for (std::size_t i{}; i < nums.size(); ++i)
        {
            if (numsSet.contains(nums[i] - 1))
            {
                int num = nums[i];
                std::size_t numLongest{2};
                while(numsSet.contains(++num))
                    ++numLongest;

                longest = std::max(numLongest, longest);
            }
        }

        return longest;
    }
};
