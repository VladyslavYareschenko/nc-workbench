class Solution {
public:
    bool isAlnum(char ch)
    {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }

    bool isPalindrome(string s)
    {
        for (std::size_t i{}, j{s.size() - 1}; i < s.size() && i < j;)
        {
            while (!isAlnum(s[i]) && i < j)
                ++i;

            char front = s[i];

            while (!isAlnum(s[j]) && i < j)
                --j;

            char back = s[j];

            if (std::tolower(front) != std::tolower(back))
                return false;


            if (i < j) {
                ++i;
                --j;
            }
        }

        return true;
    }
};
