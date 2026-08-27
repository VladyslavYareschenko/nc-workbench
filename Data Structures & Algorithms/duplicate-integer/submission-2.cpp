class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        return std::ranges::any_of(nums, [&](int num) { return !seen.insert(num).second; });
    }
};