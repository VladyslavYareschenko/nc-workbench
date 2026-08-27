class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_map<char, int> charToPos{};

        int l = 0;
        int max = 0;

        for (std::size_t r{0}; r < s.size(); ++r)
        {
            if (auto it = charToPos.find(s[r]); it != charToPos.end())
                l = std::max(it->second + 1, l);

            charToPos[s[r]] = r;
            max = std::max(max, static_cast<int>(r) - l + 1);
        }   

        return max;
    }
};
