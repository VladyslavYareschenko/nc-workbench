class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        std::array<int, 'z' - 'a'> occurance_s{};
        for (char ch : s)
            ++occurance_s['z' - ch];

        for (char ch : t)
            --occurance_s['z' - ch];

        return std::ranges::all_of(occurance_s, std::equals_to<>{}, 0);
    }
};
