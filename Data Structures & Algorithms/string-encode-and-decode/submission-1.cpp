class Solution {
public:

    string encode(vector<string>& strs)
    {
        std::ostringstream stream;

        for (auto& str : strs)
        {
            stream << static_cast<std::uint8_t>(str.size());
            stream << str;
        }

        return stream.str();
    }

    vector<string> decode(string s)
    {
        std::vector<std::string> result;

        for (std::size_t i{}; i < s.size();)
        {
            std::uint8_t len = s[i++];
            result.push_back(std::string(s.data() + i, s.data() + i + len));
            i += len; 
        }

        return result;
    }
};
