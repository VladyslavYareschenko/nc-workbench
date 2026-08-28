class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h)
    {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        int min = r;

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            int timeToEat = 0;
            for (int pile : piles)
                timeToEat += std::ceil(pile / static_cast<double>(m));

            if (timeToEat <= h)
            {
                min = std::min(m, min);
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return min;
    }
};
