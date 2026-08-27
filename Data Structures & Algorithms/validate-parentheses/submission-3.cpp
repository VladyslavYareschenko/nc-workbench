class Solution {
public:
    bool isValid(string s)
    {
        std::stack<char> ps;

        std::unordered_map<char, char> openClose = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        for (char ch : s)
        {
            auto closing = openClose.find(ch);
            if (closing != openClose.end())
            {
                if (ps.empty())
                    return false;

                if (ps.top() == closing->second)
                    ps.pop();
            }
            else
            {
                ps.push(ch);
            }
        }

        return ps.empty();
    }
};
