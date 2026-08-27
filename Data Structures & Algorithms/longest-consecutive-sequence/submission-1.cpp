class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        std::unordered_set<int> numsSet{nums.begin(), nums.end()};

        std::size_t longest{};

        for (std::size_t i{}; i < nums.size(); ++i)
        {
            int num = nums[i];
            std::size_t numLongest{1};
            while(numsSet.find(++num) != numsSet.end())
            {
                ++numLongest;
            }

            longest = std::max(numLongest, longest);
        }

        return longest;
    }
};
