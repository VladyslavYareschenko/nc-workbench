class Solution {
public:

    string encode(vector<string>& strs)
    {
        std::stringstream stream;

        for (auto& str : strs)
        {
            stream << static_cast<std::uint8_t>(str.size());
            stream << str;
        }

        return stream.str();
    }

    vector<string> decode(string s) {

    }
};
