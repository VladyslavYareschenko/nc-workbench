class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
            return 0;

        int minprice = prices[0];
        int maxprof = 0;

        for (std::size_t i{}; i < prices.size(); ++i)
        {
            minprice = std::min(prices[i], minprice);
            maxprof = std::max(maxprof, prices[i] - minprice);
        }

        return maxprof;
    }
};
