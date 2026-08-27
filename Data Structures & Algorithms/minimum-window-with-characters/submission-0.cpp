class Solution {
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty() || t.size() > s.size())
            return {};

        std::unordered_map<char, int> occurancesT;
        for (char ch : t)
            ++occurancesT[ch];

        std::unordered_map<char, int> occurancesS;

        auto containsAllOfT = [&occurancesT, &occurancesS]
        {
            return std::ranges::all_of(occurancesT, [&occurancesS](const auto& elementT)
            {
                auto it = occurancesS.find(elementT.first);
                return it != occurancesS.end() && it->second >= elementT.second;
            });
        };

        std::size_t minLength = std::numeric_limits<std::size_t>::max();
        std::pair<std::size_t, std::size_t> output;

        for (std::size_t l{}, r{}; r < s.size(); ++r)
        {
            ++occurancesS[s[r]];
            if (containsAllOfT())
            {
                for (; l <= r; ++l)
                {
                    --occurancesS[s[l]];
                    if (!containsAllOfT())
                    {
                        if (std::size_t length = r - l + 1; minLength > length)
                        {
                            minLength = length;
                            output = {l, r};
                        }

                        ++l;
                        break;
                    }
                }
            }
        }

        return std::string(s.data() + output.first, output.second - output.first + 1);
    }
};
