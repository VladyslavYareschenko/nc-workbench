class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed)
    {
        std::vector<std::pair<int /* pos */, int /* speed */>> cars;
        cars.reserve(position.size());
        
        for (std::size_t i{}; i < position.size(); ++i)
        {
            int pos = position[i];
            int sp = speed[i];

            std::size_t insertPos{};

            for (std::size_t l{}, r{cars.size()}; l < r;)
            {
                std::size_t mid = l + (r - l) / 2;

                if (pos > cars[mid].first)
                    l = mid + 1;
                else
                    r = mid;

                insertPos = l;
            }

            cars.insert(cars.begin() + insertPos, std::make_pair(pos, sp));
        }

        std::stack<double> arrivalTime;

        for (const auto& [pos, sp] : cars)
            arrivalTime.push(static_cast<double>(target - pos) / static_cast<double>(sp));

        int fleets = 0;

        while (!arrivalTime.empty())
        {
            double leaderArrival = arrivalTime.top();
            arrivalTime.pop();

            while (!arrivalTime.empty() && arrivalTime.top() <= leaderArrival)
                arrivalTime.pop();

            fleets++;
        }

        return fleets;
    }
};
