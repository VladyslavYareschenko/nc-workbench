class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> numberToFrequency{};
        numberToFrequency.reserve(nums.size());
        for (std::size_t i{}; i < nums.size(); ++i)
            ++numberToFrequency[nums[i]];

        std::vector<int> frequencyList(nums.size() + 1, std::numeric_limits<int>::min());
        for (const auto& [num, freq] : numberToFrequency)
            frequencyList[freq] = num;

        std::vector<int> top_items{};
        top_items.reserve(k);
        for (auto it = frequencyList.rbegin(); it != frequencyList.rend(); ++it)
        {
            if (*it != std::numeric_limits<int>::min())
                top_items.push_back(*it);

            if (top_items.size() == k)
                break;
        }

        return top_items;
    }
};
