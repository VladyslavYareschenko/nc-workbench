class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        for (std::size_t l{},  r{numbers.size() - 1}; l < r;)
        {
            int sum = numbers[l] + numbers[r];
            if (sum > target)
            {
                --r;
            }
            else if (sum < target)
            {
                ++l;
            }
            else
            {
                return {static_cast<int>(l) + 1, static_cast<int>(r) + 1};
            }
        }

        return {};
    }
};
