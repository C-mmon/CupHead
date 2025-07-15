     vector<pair<int, double>> store;

        // Store position and time to reach target
        for (int i = 0; i < position.size(); i++) {
            store.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }

        // Sort by position in descending order (furthest car first)
        sort(store.begin(), store.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        stack<double> fleet;
        
        for (const auto& car : store) {
            double time = car.second;
            // If stack is empty or this car takes longer than the car in front, it forms a new fleet
            if (fleet.empty() || time > fleet.top()) {
                fleet.push(time);
            }
        }

        return fleet.size();
