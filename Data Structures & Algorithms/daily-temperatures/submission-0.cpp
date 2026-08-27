class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures)
    {
        std::vector<int> result(temperatures.size(), 0);

        std::stack<std::size_t> greaterTempIndices;

        for (std::size_t i{}; i < temperatures.size(); ++i)
        {
            while(!greaterTempIndices.empty() && temperatures[greaterTempIndices.top()] < temperatures[i])
            {
                std::size_t idx = greaterTempIndices.top();
                result[idx] = static_cast<int>(i - idx);
                greaterTempIndices.pop();
            }

            greaterTempIndices.push(i);
        }

        return result;
    }
};
