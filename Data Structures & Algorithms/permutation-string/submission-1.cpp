class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        std::array<int, 'z' - 'a' + 1> s1Occ{};
        std::array<int, 'z' - 'a' + 1> s2Occ{};

        for (char ch : s1)
            ++s1Occ[ch - 'a'];

        for (std::size_t l{}, r{}; r < s2.size(); ++r)
        {
            ++s2Occ[s2[r] - 'a'];

            if (r - l + 1 == s1.size())
            {
                if (std::ranges::equal(s1Occ, s2Occ))
                    return true;

                --s2Occ[s2[l] - 'a'];
                ++l;
            }
        }

        return false;
    }
};
