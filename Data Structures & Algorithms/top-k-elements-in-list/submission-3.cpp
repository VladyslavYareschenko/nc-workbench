class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> numberToFrequency{};
        numberToFrequency.reserve(nums.size());
        for (std::size_t i{}; i < nums.size(); ++i)
            ++numberToFrequency[nums[i]];

        std::vector<std::vector<int>> frequencyList(nums.size() + 1, std::vector<int>{});
        for (const auto& [num, freq] : numberToFrequency)
            frequencyList[freq].push_back(num);

        std::vector<int> top_items{};
        top_items.reserve(k);
        for (auto it = frequencyList.rbegin(); it != frequencyList.rend(); ++it)
        {
            for (int num : *it)
                top_items.push_back(num);

            if (top_items.size() == k)
                break;
        }

        return top_items;
    }
};
