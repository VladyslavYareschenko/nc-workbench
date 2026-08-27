#include <vector>
#include <unordered_map>

// Включаем оптимизацию ввода-вывода LeetCode
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_pos;
        
        // 1. Резервируем память, чтобы избежать дорогого рехэширования
        num_to_pos.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int desiredNum = target - num;
            auto it = num_to_pos.find(desiredNum);

            if (it != num_to_pos.end()) {
                return {it->second, i};
            }

            // 2. Используем [] вместо emplace для простых типов
            num_to_pos[num] = i;
        }

        return {};
    }
};
