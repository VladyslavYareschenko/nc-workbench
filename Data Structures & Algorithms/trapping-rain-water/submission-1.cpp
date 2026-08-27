class Solution {
public:
    /*
    int trap(vector<int>& height)
    {
        int total = 0;

        std::vector<int> leftH(height.size(), height[0]);
        std::vector<int> rightH(height.size(), height[height.size() - 1]);

        for (std::size_t i{1}; i < height.size(); ++i)
        {
            leftH[i] = std::max(leftH[i - 1], height[i]);
            rightH[height.size() - 1 - i] = std::max(rightH[height.size() - i], 
                                                     height[height.size() - 1 - i]);
        }

        for (std::size_t i{}; i < height.size(); ++i)
        {
            total += (std::min(leftH[i], rightH[i]) - height[i]);
        }

        return total;
    }
    */

    int trap(vector<int>& height)
    {
        int total = 0;

        if (height.size() < 3)
            return 0;

        int lH = height[0];
        int rH = height[height.size() - 1];

        for (std::size_t l{0}, r{height.size() - 1}; l < r;)
        {
            if (lH < rH)
            {
                ++l;

                lH = std::max(lH, height[l]);

                if (std::min(lH, rH) > height[l])
                    total += std::min(lH, rH) - height[l];
            }
            else
            {
                --r;

                rH = std::max(rH, height[r]);

                if (std::min(lH, rH) > height[r])
                    total += std::min(lH, rH) - height[r];
            }
        }

        return total;
    }
};
