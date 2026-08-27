class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed)
    {
        std::vector<std::pair<int /* pos */, int /* speed */>> cars;
        cars.reserve(position.size());
        
        for (std::size_t i{}; i < position.size(); ++i)
            cars.emplace_back(position[i], speed[i]);

        std::sort(cars.begin(), cars.end(), std::greater<>());

        std::vector<double> arrivalTime;
        arrivalTime.reserve(cars.size());

        for (const auto& [pos, sp] : cars)
            arrivalTime.push_back(static_cast<double>(target - pos) / sp);

        int fleets = 0;
        double leaderArrival = .0;
        
        for (double arrival : arrivalTime)
        {
            if (arrival > leaderArrival)
            {
                ++fleets;
                leaderArrival = arrival;
            }
        }

        return fleets;
    }
};
