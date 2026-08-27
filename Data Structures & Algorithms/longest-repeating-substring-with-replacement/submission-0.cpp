class Solution {
public:
    int characterReplacement(string s, int k)
    {
        if (s.size() < 2)
            return s.size();

        std::array<int, 'Z' - 'A' + 1> occ{};
        int maxF = 0;
        int output = 0;

        for (std::size_t l{}, r{}; r < s.size(); ++r)
        {
            maxF = std::max(maxF, ++occ[s[r] - 'A']);

            if (r - l + 1 > maxF + k)
            {
                --occ[s[l] - 'A'];
                ++l;
            }

            output = std::max(output, static_cast<int>(r - l + 1));
        }

        return output;
    }
};
