using StringDecomposition = std::array<int, 'z' - 'a' + 1>;

struct SpanHash
{
    std::size_t operator()(const StringDecomposition& arr) const
    {
        return std::hash<std::string_view>{}(
            std::string_view{
                reinterpret_cast<const char*>(arr.data()),
                sizeof(arr)
        });
    }
};

struct SpanEqual
{
    bool operator()(const StringDecomposition& lhs, const StringDecomposition& rhs) const
    {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
};

class Solution {
public:
    StringDecomposition getDecomposition(std::string_view sv)
    {
        StringDecomposition decomposition{};
        for (char ch : sv)
            ++decomposition['z' - ch];

        return decomposition;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::vector<std::vector<std::string>> groups;
        std::unordered_map<StringDecomposition, std::size_t, SpanHash, SpanEqual> 
            decompositionToGroupPos;

        for (auto& str : strs)
        {
            auto decomposition = getDecomposition(str);
            
            auto [it, inserted] = decompositionToGroupPos.insert({decomposition, groups.size()});

            if (inserted)
            {
                groups.push_back({});
            }
            
            groups[it->second].push_back(std::move(str));
        }

        return groups;
    }
};
